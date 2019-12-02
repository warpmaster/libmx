#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    if (size <= 0)
        return NULL;

    void *new_ptr = malloc(size);

    if (!new_ptr)
        return NULL;

    if (!ptr)
        return new_ptr;

    size_t size_ptr = malloc_usable_size(ptr); // change to malloc_size()
    //printf("%zu\n", size_ptr);
    mx_memcpy(new_ptr, ptr, (size_ptr > size ? size : size_ptr));
    free(ptr);

    return new_ptr;
}
