#include "sort.h"
void swap_nodes(listint_t **list, listint_t *left, listint_t *right);

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the doubly linked list
 * @left: Pointer to the left node
 * @right: Pointer to the right node
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	if (left->prev)
		left->prev->next = right;
	if (right->next)
		right->next->prev = left;
	left->next = right->next;
	right->prev = left->prev;
	left->prev = right;
	right->next = left;
	if (!right->prev)
		*list = right;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using the Cocktail Shaker sort
 * algorithm
 * @list: Pointer to the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *left, *right, *current;

	if (!list || !*list)
		return;
	current = *list;
	while (swapped)
	{
		swapped = 0;
		while (current->next)
		{
			right = current->next;
			if (current->n > right->n)
			{
				swap_nodes(list, current, right);
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->next;
		}
		if (!swapped)
			break;
		swapped = 0;
		while (current->prev)
		{
			left = current->prev;
			if (left->n > current->n)
			{
				swap_nodes(list, left, current);
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->prev;
		}
	}
}
