#ifndef LCT__H_
# define LCT__H_

#  ifdef DEBUG
#    define debug(Args...) fprintf(stderr, ## Args)
#  else
#    define debug(Args...) { }
#  endif

#  define info(Args...) fprintf(stdout, ## Args)
#  define warning(Args...) fprintf(stderr, ## Args)
#  define error(Args...) fprintf(stderr, ## Args)

#endif /* !LCT__H_ */
