#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers using cocktail
 * sort
 *
 * @list: pointer to head of doubly linked list
 */

void cocktail_sort_list(listint_t **list)
{
	bool swapped = false;
	listint_t *current;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		current = *list;
		swapped = false;

		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				swap_ints((int *)&current->n, (int *)&current->next->n);
				print_list(*list);
				swapped = true;
			}

			current = current->next;
		}

		if (!swapped)
			break;

		while (current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{
				swap_ints((int *)&current->n, (int *)&current->prev->n);
				print_list(*list);
				swapped = true;
			}

			current = current->prev;
		}
	} while (swapped);
}
