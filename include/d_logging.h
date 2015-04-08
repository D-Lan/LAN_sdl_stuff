
#define DEBUG

#ifndef LAN_LOGGING_H
#define LAN_LOGGING_H




#   ifdef DEBUG
        #include <cstdio>
        static int (*d_log)(const char*, ...) = printf;
#   else
        static inline void d_log(...) { }
#   endif


#endif // If LAN_LOGGING_H
