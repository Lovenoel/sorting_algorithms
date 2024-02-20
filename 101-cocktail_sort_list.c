#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * in ascending order  using the Cocktail Shaker sort algorithm.
 * @list: Double pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped;
    listint_t *current;

    if (list == NULL || *list == NULL)
        return;
    do
    {
        swapped = 0;
        for (current = *list; current->next != NULL; current = current->next)
        {
            if (current->n > current->next->n)
            {
                swap_nodes(current, current->next, list);
                print_list(*list);
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
        swapped = 0;
        for (; current->prev != NULL; current = current->prev)
        {
            if (current->prev->n > current->n)
            {
                swap_nodes(current->prev, current, list);
                print_list(*list);
                swapped = 1;
            }
        }
    } while (swapped);
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 *
 * @a: First node to swap
 * @b: Second node to swap
 * @list: Double pointer to the head of the doubly linked list
 */
void swap_nodes(listint_t *a, listint_t *b, listint_t **list)
{
    if (a->prev != NULL)
        a->prev->next = b;

    if (b->next != NULL)
        b->next->prev = a;

    a->next = b->next;
    b->prev = a->prev;
    a->prev = b;
    b->next = a;

    if (b->prev == NULL)
        *list = b;
}
