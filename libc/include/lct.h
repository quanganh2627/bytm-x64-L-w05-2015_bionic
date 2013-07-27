#ifndef LCT_H_
# define LCT_H_

#include <sys/socket.h>
#include <sys/un.h>

#include <strings.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include <linux/kct.h>

#define PKT_SIZE(Ev) (((struct ct_event*)(Ev))->attchmt_size + sizeof(struct ct_event))
#define SK_NAME "\0crashtool_socket"

#  ifndef min
#    define min(X, Y)  ((X) > (Y) ? (Y) : (X))
#  endif
#  ifndef max
#    define max(X, Y)  ((X) < (Y) ? (Y) : (X))
#  endif


extern inline void lct_free_event(struct ct_event *ev)
{
	free(ev);
}

extern inline struct ct_event *lct_alloc_event(const char *submitter_name,
					       const char *ev_name,
					       enum ct_ev_type ev_type)
{
	struct ct_event *ev = NULL;

	ev = malloc(sizeof(*ev));
	if (!ev)
		goto error_alloc;

	bzero(ev, sizeof(*ev));

	if (submitter_name)
		strncpy(ev->submitter_name, submitter_name,
			sizeof(ev->submitter_name));

	if (ev_name)
		strncpy(ev->ev_name, ev_name,
			sizeof(ev->ev_name));

	ev->timestamp = 0x42;

	ev->type = ev_type;

	return ev;

 error_alloc:
	return NULL;
}

extern inline int lct_add_attchmt(struct ct_event **ev,
				  enum ct_attchmt_type at_type,
				  unsigned int size, const char *data)
{
	struct ct_attchmt *new_attchmt = NULL;
	struct ct_event *new_ev = NULL;
	__u32 new_size = sizeof(*new_ev) + (*ev)->attchmt_size +
		ALIGN(size + sizeof(*new_attchmt), ATTCHMT_ALIGNMENT);

	new_ev = realloc(*ev, new_size);
	if (!new_ev) {
		return -ENOMEM;
	}

	new_attchmt = (struct ct_attchmt *)
		(((char *) new_ev->attachments) + new_ev->attchmt_size);

	new_attchmt->size = size;
	new_attchmt->type = at_type;
	memcpy(new_attchmt->data, data, size);

	new_ev->attchmt_size = new_size - sizeof(*new_ev);

	*ev = new_ev;

	return 0;
}

extern inline int lct_snd_event(int sock_fd, struct ct_event* ev)
{
	struct sockaddr_un addr;
	ssize_t nb_sent = 0;

	assert(ev != NULL);

	bzero(&addr, sizeof(addr));
	addr.sun_family = AF_UNIX;
	memcpy(addr.sun_path, SK_NAME,
	       min(sizeof(addr.sun_path), sizeof(SK_NAME)));
 retry:
	nb_sent = sendto(sock_fd, ev, PKT_SIZE(ev),
			 0x0, (const struct sockaddr*) &addr,
			 sizeof(addr));
	if (nb_sent < (ssize_t) PKT_SIZE(ev)) {
		if (errno != EINTR)
			return -errno;
		else
			goto retry;
	}

	return 0;
}

extern inline int lct_rcv_event(int sock_fd, struct ct_event** ev)
{
	ssize_t nb_read = 0;
	size_t len = 0;
	char* buf[sizeof(**ev)];

	assert(ev != NULL);

 retry_first_recv:
	nb_read = recvfrom(sock_fd, buf, sizeof(buf),
			   MSG_PEEK, NULL, NULL);
	if (nb_read < 0 ) {
		if (errno != EINTR)
			goto err;
		else
			goto retry_first_recv;
	}

	len = ((struct ct_event*)buf)->attchmt_size + sizeof(**ev);

	if (!(*ev = malloc(len)))
		return -errno;

 retry_second_recv:
	nb_read = recvfrom(sock_fd, *ev, len, 0, NULL, NULL);
	if (nb_read < 0 ) {
		if (errno != EINTR)
			goto err_free;
		else
			goto retry_second_recv;
	}

	return 0;

 err_free:
	free(*ev);
	*ev = NULL;
 err:
	return -errno;
}

extern inline int lct_server_init(void)
{
	struct sockaddr_un addr;
	int sock_fd = -1;
	int ret = 0;

	sock_fd = socket(AF_UNIX, SOCK_DGRAM, 0);
	if (sock_fd < 0)
		return -errno;

	bzero(&addr, sizeof(addr));

	addr.sun_family = AF_UNIX;
	memcpy(addr.sun_path, SK_NAME,
	       min(sizeof(addr.sun_path), sizeof(SK_NAME)));

	if (bind(sock_fd, (struct sockaddr* const) &addr, sizeof(addr))) {
		ret = -errno;
		goto error;
	}

	return sock_fd;

 error:
	close(sock_fd);
	return ret;
}

extern inline int lct_client_init(void)
{
	int sock_fd = -1;

	sock_fd = socket(AF_UNIX, SOCK_DGRAM, 0);
	if (sock_fd < 0)
		return -errno;

	fprintf(stderr, "lct_client_init %d", sock_fd);

	return sock_fd;
}

extern inline int lct_client_exit(int sock_fd)
{
	return close(sock_fd);
}

extern inline int lct_server_exit(int sock_fd)
{
	return close(sock_fd);
}

extern inline int __lct_log_data(struct ct_event ** ev, const char* data[3])
{
	int ret = -1;

	assert(ev != NULL);
	assert(*ev != NULL);

	if (data[0])
		if ((ret = lct_add_attchmt(ev, CT_ATTCHMT_DATA0,
					   strlen(data[0]), data[0])))
			goto out;
	if (data[1])
		if ((ret = lct_add_attchmt(ev, CT_ATTCHMT_DATA1,
					   strlen(data[1]), data[1])))
			goto out;
	if (data[2])
		if ((ret = lct_add_attchmt(ev, CT_ATTCHMT_DATA1,
					   strlen(data[2]), data[2])))
			goto out;

	return 0;

 out:
	return ret;
}

extern inline int lct_log_event(int sock_fd, struct ct_event *ev)
{
	return lct_snd_event(sock_fd, ev);
}

extern inline int lct_log_crash(const char* submitter_name,
				const char* ev_name,
				const char* data[3])
{
	struct ct_event *ev = NULL;

	ev = lct_alloc_event(submitter_name, ev_name, CT_EV_CRASH);
	if (!ev) {
		return -ENOMEM;
	}

	if (data[0]) {
		puts(data[0]);
	}

	return -1;
}
extern inline  int lct_log_info(int sock_fd,
				const char* submitter_name,
				const char* ev_name,
				const char* data[3])
{
	struct ct_event *ev = NULL;
	int ret = -1;

	ev = lct_alloc_event(submitter_name, ev_name, CT_EV_CRASH);
	if (!ev) {
		return -ENOMEM;
	}


	if ((ret = __lct_log_data(&ev, data)))
		goto out_malloc;

	if ((ret = lct_log_event(sock_fd, ev)))
		goto out_malloc;

	lct_free_event(ev);

	return 0;

 out_malloc:
	lct_free_event(ev);
	return ret;
}

extern inline int lct_log_error(int sock_fd,
				const char* submitter_name,
				const char* ev_name,
				const char* data[3])
{
	struct ct_event *ev = NULL;
	int ret = -1;

	ev = lct_alloc_event(submitter_name, ev_name, CT_EV_CRASH);
	if (!ev) {
		return -ENOMEM;
	}

	if ((ret = __lct_log_data(&ev, data)))
		goto out_malloc;

	if ((ret = lct_log_event(sock_fd, ev)))
		goto out_malloc;

	lct_free_event(ev);

	return 0;

 out_malloc:
	lct_free_event(ev);
	return ret;
}

extern inline int lct_log_stat(int sock_fd,
			       const char *submitter_name,
			       const char *ev_name)
{
	struct ct_event *ev = NULL;
	int ret = -1;

	ev = lct_alloc_event(submitter_name, ev_name, CT_EV_STAT);
	if (!ev) {
		return -ENOMEM;
	}

	if ((ret = lct_log_event(sock_fd, ev)))
		return ret;

	lct_free_event(ev);

	return 0;
}

#endif /* !LCT_H_ */
