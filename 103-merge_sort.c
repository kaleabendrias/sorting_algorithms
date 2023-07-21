#include "sort.h"

/**
 * merge - Merges two subarrays into one sorted array
 * @array: array
 * @size: The total size
 * @left: The left subarray
 * @left_size: The size of the left
 * @right: The right subarray
 * @right_size: The size of the right subarray
 * Return: none
 */

void merge(int *array, size_t size, int *l, size_t l_s, int *r, size_t r_s)
{
	int i, j, k;
	int *merged;

	i = 0, j = 0, k = 0;
	printf("Merging...\n[left]: ");
	print_array(l, l_s);
	printf("[right]: ");
	print_array(r, r_s);
	merged = malloc(sizeof(int) * size);
	if (!merged)
		return;
	while (i < (int)l_s && j < (int)r_s)
	{
		if (l[i] <= r[j])
			merged[k++] = l[i++];
		else
			merged[k++] = r[j++];
	}
	while (i < (int)l_s)
		merged[k++] = l[i++];
	while (j < (int)r_s)
		merged[k++] = r[j++];
	for (i = 0; i < (int)size; i++)
		array[i] = merged[i];
	printf("[Done]: ");
	print_array(array, size);
	free(merged);
}

/**
 * merge_sort - Sorts an array of integers in ascending
 * @array: The array to be sorted
 * @size: The size
 * Return: none
 */

void merge_sort(int *array, size_t size)
{
	size_t mid, i;
	int *left, *right;

	mid = size / 2;
	if (!array || size < 2)
		return;
	if (size <= 1)
		return;
	left = malloc(sizeof(int) * mid);
	right = malloc(sizeof(int) * (size - mid));
	if (!left || !right)
	{
		free(left);
		free(right);
		return;
	}
	for (i = 0; i < mid; i++)
		left[i] = array[i];
	for (i = mid; i < size; i++)
		right[i - mid] = array[i];
	merge_sort(left, mid);
	merge_sort(right, size - mid);
	merge(array, size, left, mid, right, size - mid);
	free(left);
	free(right);
}
