//source : inspired by musl.libc implementation

#define CLOCK_REALTIME 0

struct timespec {
    long tv_sec;
    long tv_nsec;
};

int nanosleep(const struct timespec *req, struct timespec *rem);
