#include "libmx.h"

void mx_pop_back(t_list **head) {
    t_list *walker = NULL;

    if (head == NULL || *head == NULL)
        return;

    walker = *head;
    if (walker->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    for ( ; walker->next->next != NULL; walker = walker->next);
    free(walker->next);
    walker->next = NULL;
}
