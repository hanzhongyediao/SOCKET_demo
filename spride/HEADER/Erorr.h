#ifndef Erorr_H_
#define Erorr_H_

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#undef EXIT_MASSAGE(massage)
#define EXIT_MASSAGE(massage) \
    do{ \
        perror(massage); \
        exit(EXIT_FAILURE); \ 
} while(0)

#undef ERROR
#define ERROR -1
#undef SUCCESS 
#define SUCCESS 0
#undef CLOSE 
#define CLOSE 1

#endif
    
