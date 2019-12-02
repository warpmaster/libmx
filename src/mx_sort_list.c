#include "libmx.h"

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
    if (!lst) return NULL;

    for (t_list *i = lst; i != NULL; i = i->next) {
        for (t_list *j = i->next; j != NULL; j = j->next) {
            //printf("comparing %s and %s\n", *(char **)i->data, *(char **)j->data);
            if (cmp(i->data, j->data)) {
                void *temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    return lst;
}
