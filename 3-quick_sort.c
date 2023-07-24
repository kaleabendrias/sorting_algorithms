#include "sort.h"

/**
 * swap - swaps two integers
 * @a: the first element
 * @b: the second element
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * partition - the partitio function for the quick sort sorting method
 * @array: the array to sort
 * @start: the start of the array
 * @end: the end of the array
 * @size: the size of the array
 * Return: it returns the position of thr pivot
 */
int partition(int *array, int start, int end, size_t size)
{
	int pivot = array[end];
	int i, j;

	i = start;
	for (j = start; j < end; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != end)
	{
		swap(&array[i], &array[j]);
		print_array(array, size);
	}
	return (i);
}

/**
 * quick_sort_helper - uses recorsion to sort the divded array with
 * the help of the pivot
 * @array: the array to sort
 * @start: the start of the array
 * @end: the end of the array
 * @size: the size of the array
 */
void quick_sort_helper(int *array, int start, int end, size_t size)
{
	int pivot;

	if (start < end)
	{
		pivot = partition(array, start, end, size);
		quick_sort_helper(array, start, pivot - 1, size);
		quick_sort_helper(array, pivot + 1, end, size);
	}
}

/**
 * quick_sort - the main quick sort funtion
 * @array: the array
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return;
	quick_sort_helper(array, 0, size - 1, size);
}
