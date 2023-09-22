#include "sort.h"
#include <stdlib.h>
#include <stdint.h>

/**
 * get_max - Get the maximum element in an array
 * @array: The array
 * @size: The size of the array
 * Return: The maximum element
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return max;
}

/**
 * counting_sort_radix - Counting sort algorithm for radix sort
 * @array: The array to be sorted
 * @size: The size of the array
 * @digit: The current significant digit
 */
void counting_sort_radix(int *array, size_t size, int digit)
{
	int *output = malloc(sizeof(int) * size);
	int count[10] = {0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / digit) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = size - 1; i < SIZE_MAX; i--)
	{
		output[count[(array[i] / digit) % 10] - 1] = array[i];
		count[(array[i] / digit) % 10]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
	free(output);
}

/**
 * radix_sort - Sorts an array of integers using radix sort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max = get_max(array, size);
	int digit;

	for (digit = 1; max / digit > 0; digit *= 10)
	{
		counting_sort_radix(array, size, digit);
		print_array(array, size);
	}
}
