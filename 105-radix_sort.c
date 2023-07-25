#include "sort.h"

/**
 * counting_sort - sorts an array using the radix sort method
 * @array: the array
 * @size: the size of the array
 * @exp: the exponent, keeps track of the position of the digit being
 * considered in the radix sorting algorithm
 * @output: temporary array holding the sorted elemnts
 */
void counting_sort(int *array, size_t size, int exp, int *output)
{
	int count[10];
	size_t i;

	memset(count, 0, sizeof(count));
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
 * find_max - finds the maximum element in an array of integers
 * @array: the array
 * @size: the size of the array
 * Return: the max element of the array
 */
int find_max(int *array, size_t size)
{
	int max;
	size_t i;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * radix_sort - the radix sort main function
 * @array: the array to sort using the radix sort algorithm
 * @size: the size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp, *output;

	if (array == NULL || size < 2)
		return;

	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;

	max = find_max(array, size);
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort(array, size, exp, output);
		print_array(array, size);
	}
	free(output);
}
