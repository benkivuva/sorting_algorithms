#include "sort.h"
void swap_nodes(listint_t *node1, listint_t *node2);
/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 *                      in ascending order using Cocktail shaker sort
 * @list: Pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
    int swapped = 1;
    listint_t *current;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    while (swapped)
    {
        swapped = 0;

        /* Forward pass */
        current = *list;
        while (current->next != NULL)
        {
            if (current->n > current->next->n)
            {
                swap_nodes(current, current->next);
                print_list(*list);
                swapped = 1;
            }
            else
            {
                current = current->next;
            }
        }

        if (!swapped)
            break;

        swapped = 0;

        /* Backward pass */
        current = current->prev;
        while (current->prev != NULL)
        {
            if (current->n < current->prev->n)
            {
                swap_nodes(current->prev, current);
                print_list(*list);
                swapped = 1;
            }
            else
            {
                current = current->prev;
            }
        }
    }
}

/**
 * swap_nodes - Swaps two adjacent nodes in a doubly linked list
 * @node1: First node to swap
 * @node2: Second node to swap
 */
void swap_nodes(listint_t *node1, listint_t *node2)
{
    if (node1->prev != NULL)
        node1->prev->next = node2;
    if (node2->next != NULL)
        node2->next->prev = node1;

    node1->next = node2->next;
    node2->prev = node1->prev;

    node1->prev = node2;
    node2->next = node1;
}
