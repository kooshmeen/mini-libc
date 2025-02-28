// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	char *dest = destination;
    while (*source) {
        *dest++ = *source++;
    }
    *dest = '\0';
	return dest;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	char *dest = destination;
	size_t i = 0;
    for (i = 0; i < len && *source; i++) {
        dest[i] = source[i];
    }
    for (; i < len; i++) {
        dest[i] = '\0';
    }
	return dest;
}

char *strcat(char *destination, const char *source)
{
	char *dest = destination;
    while (*dest) {
        dest++;
    }
    while (*source) {
        *dest++ = *source++;
    }
    *dest = '\0';
	return dest;
}

char *strncat(char *destination, const char *source, size_t len)
{
	char *dest = destination;
    while (*dest) {
        dest++;
    }
    size_t i;
    for (i = 0; i < len && source[i]; i++) {
        dest[i] = source[i];
    }
    dest[i] = '\0';
	return dest;
}

int strcmp(const char *str1, const char *str2)
{
	while (*str1 && *str2 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	while (len > 0 && *str1 && *str2 && (*str1 == *str2)) {
        str1++;
        str2++;
        len--;
    }
    if (len == 0) {
        return 0;
    }
    return *str1 - *str2;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	while (*str++) {
        i++;
    }

	return i;
}

char *strchr(const char *str, int c)
{
	while (*str) {
        if (*str == c) {
            return (char *)str;
        }
        str++;
    }
    return NULL;
}

char *strrchr(const char *str, int c)
{
	char *ch_p = NULL;
    while (*str) {
        if (*str == c) {
            ch_p = (char *)str;
        }
        str++;
    }
    return ch_p;
}

char *strstr(const char *haystack, const char *needle)
{
	int len = strlen(needle);
    while (*haystack) {
        if (strncmp(haystack, needle, len) == 0) {
            return (char *)haystack;
        }
        haystack++;
    }
    return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	int len = strlen(needle);
    char *ch_p = NULL;
    while (*haystack) {
        if (strncmp(haystack, needle, len) == 0) {
            ch_p = (char *)haystack;
        }
        haystack++;
    }
    return ch_p;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	char *dest = (char *)destination;
    const char *src = (const char *)source;
	size_t i = 0;
    for (i = 0; i < num; i++) {
        dest[i] = src[i];
    }
    return dest;
}

void *memmove(void *destination, const void *source, size_t num)
{
	char *dest = (char *)destination;
    const char *src = (const char *)source;
	size_t i;
    if (dest < src) {
        for (i = 0; i < num; i++) {
            dest[i] = src[i];
        }
    } else if (dest > src) {
        for (i = num; i > 0; i--) {
            dest[i - 1] = src[i - 1];
        }
    }
    return dest;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	const char *p1 = (const char *)ptr1;
    const char *p2 = (const char *)ptr2;
	size_t i;
    for (i = 0; i < num; i++) {
        if (p1[i] < p2[i])
            return -1;
        if (p1[i] > p2[i])
            return 1;
    }
    return 0;
}

void *memset(void *source, int value, size_t num)
{
	char *dest = (char *)source;
	size_t i;
    for (i = 0; i < num; i++) {
        dest[i] = (char)value;
    }
    return source;
}
