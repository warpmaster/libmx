#include "libmx.h"

char *mx_file_to_str(const char *file) {
    const size_t b_size = 512;
    char buffer[b_size];
    int fd = -1;
    char *str = NULL;

    mx_memset(buffer, '\0', b_size);

    if (!file)
        return NULL;

    if ((fd = open(file, O_RDONLY)) == -1)
        return NULL;

    while (read(fd, buffer, b_size) > 0) {
        str = mx_strjoin(str, buffer);
        mx_memset(buffer, '\0', b_size);
    }
    close(fd);

    return str;
}
