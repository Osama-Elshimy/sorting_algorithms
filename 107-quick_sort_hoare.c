#include "sort.h"

/**
 * swap - swaps two integers
 *
 * @a: first integer
 * @b: second integer
 */

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - partitions an array
 *
 * @array: array to partition
 * @size: size of array
 * @left: left index
 * @right: right index
 *
 * Return: index of pivot
 */

int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot = array[right];
	int i = left - 1;
	int j = right + 1;

	while (true)
	{
		do {
			++i;
		} while (array[i] < pivot);

		do {
			--j;
		} while (array[j] > pivot);

		if (i >= j)
			return (i);

		swap(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
 * _quick_sort_hoare - recursively sorts an array of integers
 *
 * @array: array to sort
 * @size: size of array
 * @left: left index
 * @right: right index
 */

void _quick_sort_hoare(int *array, size_t size, int left, int right)
{
	int pivot;

	if (left >= right)
		return;

	pivot = hoare_partition(array, size, left, right);
	_quick_sort_hoare(array, size, left, pivot - 1);
	_quick_sort_hoare(array, size, pivot, right);
}

/**
 * quick_sort_hoare - sorts an array of integers in ascending order using
 * quicksort hoare
 *
 * @array: array to sort
 * @size: size of array
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	_quick_sort_hoare(array, size, 0, size - 1);
}
