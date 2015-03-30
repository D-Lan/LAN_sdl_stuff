

#ifndef LAN_LOGGING_H
#define LAN_LOGGING_H




#   ifdef DEBUG
        #include <cstdio>
        static int (*log)(const char*, ...) = printf;
#   else
        static inline void log(...) { }
#   endif


#endif // If LAN_LOGGING_H
