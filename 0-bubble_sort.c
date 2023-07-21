#include "sort.h"

/**
 * swap - swaps places of two int
 * @fir: first elemnt
 * @sec: second elem
 * Return: none
 */
void swap(int *fir, int *sec)
{
	int temp = *fir;
	*fir = *sec;
	*sec = temp;
}

/**
 * bubble_sort - sorts an array of integers in ascending order using the Bubble
 * @array: array
 * @size: size of arr
 * Return: none
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i, j;

	if (array == NULL)
		return;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
			}
		}
	}
}
