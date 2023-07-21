#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using Shell sort
 * @array: array
 * @size: size
 * Return: none
 */

void shell_sort(int *array, size_t size)
{
	size_t g, i, j;
	int temp;

	g = 1;
	if (!array || size < 2)
		return;
	while (g < size / 3)
		g = g * 3 + 1;
	while (g > 0)
	{
		for (i = g; i < size; i++)
		{
			temp = array[i];
			j = i;
			while (j >= g && array[j - g] > temp)
			{
				array[j] = array[j - g];
				j -= g;
			}
			array[j] = temp;
		}
		print_array(array, size);
		g = (g - 1) / 3;
	}
}
