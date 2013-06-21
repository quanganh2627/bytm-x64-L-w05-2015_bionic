#ifndef CTM_H_
#  define CTM_H_

#  include <sys/socket.h>
#  include "linux/kct.h"
#  include <stdint.h>

#  define DEBUG
#  ifdef DEBUG
#    define debug(Args...) fprintf(stderr, ## Args)
#  else
#    define debug(Args...) { }
#  endif

#  define info(Args...) fprintf(stdout, ## Args)
#  define warning(Args...) fprintf(stderr, ## Args)
#  define error(Args...) fprintf(stderr, ## Args)

#  define max(X, Y)  ((X) < (Y) ? (Y) : (X))

extern int thread_should_stop;
extern int sock_nl_fd;
extern int sock_fd;

enum ctm_ev_pending {
	EV_PENDING_ALL,
	EV_PENDING_NLSOCKET,
	EV_PENDING_USOCKET,
	EV_PENDING_NONE
};

/* ctm_netlink.c */
extern int ctm_nl_init(void);
extern int ctm_nl_sendto_kct(int fd, int type, const void *data, unsigned int size);
extern struct kct_packet *ctm_nl_get_packet(int fd);

/* ctm_comm.c */
extern enum ctm_ev_pending	ctm_comm_wait_event(long timeout);
extern int				lct_server_init(void);
extern void			ctm_comm_handle_socket_msg(void);
extern void			ctm_comm_handle_netlink_msg(void);

/* ctm_print.c */
extern void print_ct_attchmt(struct ct_attchmt *at);
extern void print_all_attchmnt(struct ct_event *ev);
extern void print_ct_event(struct ct_event *ev);

/* ctm_handlers.c */
extern int ct_handler(struct ct_event *ev, char *dir, char *dsuffix, char *tsuffix);

#endif /* !CTM_H_ */
