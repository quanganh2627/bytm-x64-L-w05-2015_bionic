#ifndef LCT_H_
# define LCT_H_

#include <sys/socket.h>
#include <linux/kct.h>

/* lct_ev.c */
extern int		lct_log_event(int sock_fd, struct ct_event *ev);
extern void		lct_free_event(struct ct_event*);
extern struct ct_event* lct_alloc_event(const char*, const char*, enum ct_ev_type);
extern int		lct_add_attchmt(struct ct_event **ev, enum ct_attchmt_type at_type,
					unsigned int size, const char *data);
extern int		lct_log_stat(int sock_fd, const char *submitter_name,
				     const char *ev_name);
/* lct_comm.c */
extern int		lct_snd_event(int sock_fd, struct ct_event* ev);
extern int		lct_rcv_event(int sock_fd, struct ct_event** ev);
extern int		lct_server_init(void);
extern int		lct_server_exit(int sock_fd);
extern int		lct_client_init(void);
extern int		lct_client_exit(int sock_fd);

/* */
#endif /* !LCT_H_ */
