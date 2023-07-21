#include "sort.h"

/**
 * quick_sort - sorts an array of integers using the Quick sort
 * @array: the array
 * @size: the size
 * Return: none
 */

void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - recursive helper function
 * @array: the array to be sorted
 * @low: starting index of the partition
 * @high: ending index of the partition
 * @size: the size
 * Return: none
 */

void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, pivot - 1, size);
		quick_sort_recursive(array, pivot + 1, high, size);
	}
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort
 * @array: the array to be sorted
 * @low: starting index of the partition to be sorted
 * @high: ending index of the partition to be sorted
 * @size: the size of the array
 * Return: the pivot index
 */

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j], size, array);
		}
	}
	swap(&array[i + 1], &array[high], size, array);

	return (i + 1);
}

/**
 * swap - swaps two integers
 * @a: first integer
 * @b: second integer
 *
 * Return: none
 */

void swap(int *a, int *b, size_t size, int *array)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	print_array(array, size);
}
