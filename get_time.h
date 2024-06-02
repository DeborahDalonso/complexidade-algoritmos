#include <sys/time.h>

long long timeInMicroseconds() {
    struct timeval time;
    gettimeofday(&time, NULL);
    return (long long)time.tv_sec * 1000000 + time.tv_usec;
}