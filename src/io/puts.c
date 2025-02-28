#include <unistd.h>
#include <internal/syscall.h>

void puts(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        syscall(__NR_write, 1, &str[i], 1);
    }
    syscall(__NR_write, 1, "\n", 1);
}
