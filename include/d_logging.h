
//#define DEBUG

#ifndef D_LOGGING_H
#define D_LOGGING_H




#   ifdef DEBUG
        #include <cstdio>
        static int (*d_log)(const char*, ...) = printf;
#   else
        static inline void d_log(...) { }
#   endif


#endif