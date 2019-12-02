#include "libmx.h"

void mx_push_back(t_list **list, void *data) {
    if (*list == NULL) {
        *list = mx_create_node(data);
        return;
    }

    t_list *walker = *list;
    for (; walker->next != NULL; walker = walker->next);
    walker->next = mx_create_node(data);
}
