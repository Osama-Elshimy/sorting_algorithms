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
 * shell_sort - sorts an array of integers in ascending order using the Knuth
 * sequence
 *
 * @array: array to sort
 * @size: size of array
 */

void shell_sort(int *array, size_t size)
{
	size_t i, j;
	size_t gap = 1;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	for (; gap > 0; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			for (j = i; j >= gap && array[j - gap] > array[j]; j -= gap)
			{
				swap_ints(&array[j], &array[j - gap]);
			}
		}
		print_array(array, size);
	}
}
