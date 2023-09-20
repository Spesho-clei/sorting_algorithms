#include "sort.h"
#include <stdio.h>

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending order using
 * the insertion sort algorithm
 * @list: Pointer to a pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *sorted, *next_node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = (*list)->next;
	while (current != NULL)
	{
		next_node = current->next;
		sorted = current->prev;
		while (sorted != NULL && sorted->n > current->n)
		{
			sorted->next = current->next;
			if (current->next != NULL)
				current->next->prev = sorted;
			current->prev = sorted->prev;
			current->next = sorted;
			if (sorted->prev != NULL)
				sorted->prev->next = current;
			else
				*list = current;
			sorted->prev = current;
			/* Print the list after each swap */
			print_list(*list);
			sorted = current->prev;
		}
		current = next_node;
	}
}
