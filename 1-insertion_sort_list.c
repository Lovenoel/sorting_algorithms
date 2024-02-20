#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order
 *                       using the Insertion sort algorithm.
 *
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *temp;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    current = (*list)->next;

    while (current != NULL)
    {
        temp = current->next;
        while (current->prev != NULL && current->n < current->prev->n)
        {
            current->prev->next = current->next;
            if (current->next != NULL)
                current->next->prev = current->prev;
            current->next = current->prev;
            current->prev = current->next->prev;
            current->next->prev = current;

            if (current->prev != NULL)
                current->prev->next = current;
            else
                *list = current;
            print_list(*list);
        }
        current = temp;
    }
}
