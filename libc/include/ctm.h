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

#  define STAT_TRIG_SUFFIX  "_trigger"
#  define CRASH_TRIG_SUFFIX "_trigger"
#  define INFO_TRIG_SUFFIX  "_infoevent"

#  define INFO_DATA_SUFFIX "_data"
#  define CRASH_DATA_SUFFIX "_data"

struct ct_monitor_ctx {
	int thread_should_stop;
	int sock_nl_fd;
	int sock_fd;
	char *path_stat_dir;
	char *path_crash_dir;
	char *path_info_dir;
};

enum ctm_ev_pending {
	EV_PENDING_ALL,
	EV_PENDING_NLSOCKET,
	EV_PENDING_USOCKET,
	EV_PENDING_NONE
};

typedef int (*ev_handler_t)(struct ct_event *ev);

/* ctm_netlink.c */
extern int ctm_nl_init(void);
extern int ctm_nl_exit(int fd);
extern int ctm_nl_sendto_kct(int fd, int type, const void *data, unsigned int size);
extern struct kct_packet *ctm_nl_get_packet(int fd);
extern int ctm_nl_dclr_pid(int fd);

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
extern int ct_stat_handler(struct ct_event *ev);
extern int ct_crash_handler(struct ct_event *ev);

extern struct ct_monitor_ctx ctm_ctx;

extern ev_handler_t ev_handlers[CT_EV_LAST];

#endif /* !CTM_H_ */
