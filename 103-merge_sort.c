#include "sort.h"

/**
 * merge_comp - compare merges
 * @array: the array that need to be sorted
 * @start: the start index
 * @stop: the stop index
 * @new: the new array
 * Return: void
 */
void merge_comp(int *array, size_t start, size_t stop, int *new)
{
	size_t i = start;
	size_t j, k, mid;

	j = mid = (start + stop) / 2;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + start, mid - start);
	printf("[right]: ");
	print_array(array + mid, stop - mid);
	for (k = start; k < stop; k++)
		if (i < mid && (j >= stop || array[i] <= array[j]))
		{
			new[k] = array[i++];
		}
		else
		{
			new[k] = array[j++];
		}
	printf("[Done]: ");
	print_array(new + start, stop - start);
}

/**
 * merge_top_down - sorts top-down recrucively
 * @array: the array needed to be sorted
 * @start: starting point
 * @stop: the stop index
 * @new: the output array
 * Return: void
 */
void merge_top_down(int *array, size_t start, size_t stop, int *new)
{
	size_t mid;

	mid = (start + stop) / 2;
	if (stop - start < 2)
	{
		return;
	}
	merge_top_down(new, start, mid, array);
	merge_top_down(new, mid, stop, array);
	merge_comp(array, start, stop, new);
}



/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge sort algorithm
 * @array: array that needs to be sorted
 * @size: size of array
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *new_arr;
	size_t x;

	if (!array || size < 2)
		return;

	new_arr = malloc(sizeof(int) * size);
	if (!new_arr)
		return;
	for (x = 0; x < size; x++)
		new_arr[x] = array[x];
	merge_top_down(new_arr, 0, size, array);
	free(new_arr);
}
