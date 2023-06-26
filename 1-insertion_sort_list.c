#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using Insertion sort.
 *
 * @list: Double pointer to the head of the doubly linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *key;

	if (!list || !(*list) || !(*list)->next)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		key = current;
		while (key->prev != NULL && key->n < key->prev->n)
		{
			/* Swap adjacent nodes */
			key->prev->next = key->next;
			if (key->next != NULL)
				key->next->prev = key->prev;
			key->next = key->prev;
			key->prev = key->prev->prev;
			key->next->prev = key;
			if (key->prev != NULL)
				key->prev->next = key;
			else
				*list = key;
			print_list(*list);
		}
		current = current->next;
	}
}
