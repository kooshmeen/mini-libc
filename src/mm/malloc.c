// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

//struct mem_list mem_list_head;
//void mem_list_init(void);

void *malloc(size_t size)
{
	void *ptr = mmap(0, size, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANON, -1, 0); // source - musl.libc
	return ptr;
}

void *calloc(size_t nmemb, size_t size)
{
	size_t total = nmemb * size;
	void *ptr = malloc(total);
	if (ptr) {
		memset(ptr, 0, total);
	}
	return ptr;
}

void free(void *ptr)
{
	struct mem_list *head = mem_list_find(ptr);
	munmap(ptr, head->len);
}

void *realloc(void *ptr, size_t size)
{
    struct mem_list *head = mem_list_find(ptr);
	if (head == NULL) {
		return ptr;
	}
    void *new = mremap(ptr, head->len, size, MREMAP_MAYMOVE); // source : musl.libc
    memcpy(new, ptr, size);
	free(ptr);
    return new;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	realloc(ptr, nmemb * size); // source : musl.libc
	return ptr;
}
