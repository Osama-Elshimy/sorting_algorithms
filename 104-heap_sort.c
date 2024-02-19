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
 * heapify - heapify an array
 *
 * @array: array to heapify
 * @size: size of array
 * @start: index of node to heapify
 * @print_size: print size
 */

void heapify(int *array, int size, int start, int print_size)
{
	int largest = start;
	int left = 2 * start + 1;
	int right = 2 * start + 2;

	if (left < size && array[left] > array[largest])
		largest = left;
	if (right < size && array[right] > array[largest])
		largest = right;

	if (largest != start)
	{
		swap(&array[start], &array[largest]);
		print_array(array, print_size);
		heapify(array, size, largest, print_size);
	}
}

/**
 * heap_sort - sort an array of integers in ascending order using heap sort
 *
 * @array: array to sort
 * @size: size of array
 */

void heap_sort(int *array, size_t size)
{
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}
