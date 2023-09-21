#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the Counting sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void counting_sort(int *array, size_t size)
{
	int i, max = array[0];
	int *counting_array, *temp_array;

	if (array == NULL || size < 2)
		return;
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	counting_array = malloc(sizeof(int) * (max + 1));
	temp_array = malloc(sizeof(int) * size);
	if (counting_array == NULL || temp_array == NULL)
	{
		free(counting_array);
		free(temp_array);
		return;
	}
	for (i = 0; i <= max; i++)
		counting_array[i] = 0;
	for (i = 0; i < (int)size; i++)
		counting_array[array[i]]++;
	for (i = 1; i <= max; i++)
		counting_array[i] += counting_array[i - 1];
	for (i = (int)size - 1; i >= 0; i--)
	{
		temp_array[counting_array[array[i]] - 1] = array[i];
		counting_array[array[i]]--;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = temp_array[i];
	print_array(counting_array, max + 1);
	free(counting_array);
	free(temp_array);
}
