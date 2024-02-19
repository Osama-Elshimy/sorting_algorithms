#include "sort.h"

/**
 * get_max - gets the maximum value in an array
 *
 * @array: array to search
 * @size: size of array
 *
 * Return: maximum value
 */

int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; ++i)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * counting_sort - sorts an array of integers in ascending order using counting
 * sort
 *
 * @array: array to sort
 * @size: size of array
 */

void counting_sort(int *array, size_t size)
{
	size_t i;
	int max;
	int *count;
	int *sorted;

	if (array == NULL || size < 2)
		return;

	max = get_max(array, size) + 1;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
		return;
	count = calloc(max, sizeof(int));
	if (count == NULL)
	{
		free(sorted);
		return;
	}

	for (i = 0; i < size; ++i)
		++count[array[i]];
	for (i = 1; (int)i < max; ++i)
		count[i] += count[i - 1];

	print_array(count, max);

	for (i = 0; i < size; ++i)
	{
		sorted[count[array[i]] - 1] = array[i];
		--count[array[i]];
	}

	for (i = 0; i < size; ++i)
		array[i] = sorted[i];

	free(sorted);
	free(count);
}
