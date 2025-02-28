#include <unistd.h>
#include <internal/syscall.h>
#include <time.h>

//source : musl.libc

unsigned int sleep(unsigned int seconds) {
    struct timespec tv = { // source : musl.libc
        .tv_sec = seconds,
        .tv_nsec = 0
    };
    if (nanosleep(&tv, &tv))
        return tv.tv_sec;
    return 0;
}

int nanosleep(const struct timespec *req, struct timespec *rem) {
    int ret = syscall(__NR_clock_nanosleep, CLOCK_REALTIME, 0, req, rem);
    return ret;
}
