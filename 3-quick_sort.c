#include "sort.h"
/**
 * swap - swaps 2 int together
 * @array: array
 * @size: size of array
 * @a: first int
 * @b: sec int
 * Return: void
 */
void swap(int *array, size_t size, int *a, int *b)
{
	if (a != b)
	{
		*a = *a + *b;
		*b = *a - *b;
		*a = *a - *b;
		print_array((const int *)array, size);
	}
}

/**
 * partition - itirate over the input array, swapping elements
 * that are strictly less than a pre-selected pivot element
 * @arr: array that needs to be sorted
 * @size: size of array
 * @low: lowest index
 * @high: highest index
 * Return: pivot in its right place
 *
 */
size_t partition(int arr[], size_t size, ssize_t low, ssize_t high)
{
	int pivot;
	int i, j;

	pivot = arr[high];
	i = low;

	for (j = low; j < high; j++)
	{
		if (arr[j] < pivot)
		{
			swap(arr, size, &arr[j], &arr[i++]);
		}
	}
	swap(arr, size, &arr[i], &arr[high]);
	return (i);
}

/**
 * quicksort - quick sort with lomuto partition scheme
 * @array: array that needs to be sorted
 * @size: size of array
 * @low: the lowest index
 * @high: the highest index
 * Return: Void
 */
void quicksort(int *array, size_t size, ssize_t low, ssize_t high)
{
	if (low < high)
	{
		size_t part = partition(array, size, low, high);

		quicksort(array, size, low, part - 1);
		quicksort(array, size, part + 1, high);
	}
}

/**
 * quick_sort -  sorts an array of integers in ascending
 * order using the Quick sort algorithm
 * @array: array that needs to be sorted
 * @size: size of array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (!array || !size)
		return;
	quicksort(array, size, 0, size - 1);
}
