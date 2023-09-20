#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - Sorts an array of integers in
 * ascending order using bubble sort
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;
	int swapped;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				swapped = 1;
				/* Print array after each swap */
				print_array(array, size);
			}
		}
		/* If no elements were swapped, the array is already sorted */
		if (!swapped)
			break;
	}
}
