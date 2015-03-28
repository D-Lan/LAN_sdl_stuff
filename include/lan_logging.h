

#ifndef LAN_LOGGING_H
#define LAN_LOGGING_H

#include <cstdio>


#   ifdef DEBUG
        static int (*log)(const char*, ...) = printf;
#   else
        static inline int log(...) { }
#   endif


#endif // If LAN_LOGGING_H
