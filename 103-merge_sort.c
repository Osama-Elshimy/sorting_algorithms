#include "sort.h"

/**
 * merge - merges
 *
 * @array: array
 * @left: left
 * @mid: mid
 * @right: right
 * @temp: temp
 */

void merge(int *array, int left, int mid, int right, int *temp)
{
	int i = left;
	int j = mid;
	int k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, mid - left);
	printf("[right]: ");
	print_array(array + mid, right - mid);

	while (i < mid && j < right)
	{
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}

	while (i < mid)
		temp[k++] = array[i++];
	while (j < right)
		temp[k++] = array[j++];

	for (i = left, k = 0; i < right; ++i, ++k)
		array[i] = temp[k];

	printf("[Done]: ");
	print_array(temp, k);
}

/**
 * _merge_sort - sorts an array of integers in ascending order using merge sort
 *
 * @array: array to sort
 * @left: left index
 * @right: right index
 * @temp: temp array
 */

void _merge_sort(int *array, int left, int right, int *temp)
{
	int mid;

	if (right - left <= 1)
		return;

	mid = left + (right - left) / 2;

	_merge_sort(array, left, mid, temp);
	_merge_sort(array, mid, right, temp);
	merge(array, left, mid, right, temp);
}

/**
 * merge_sort - sorts an array of integers in ascending order using merge sort
 *
 * @array: array to sort
 * @size: size of array
 */

void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
		return;

	_merge_sort(array, 0, size, temp);

	free(temp);
}
