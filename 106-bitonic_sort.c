#include "sort.h"
#include <stdio.h>

/**
 * bitonic_merge - Recursively performs bitonic merge
 * @array: The array
 * @size: The size of the array
 * @dir: The direction (1 for ascending, 0 for descending)
 */
static void bitonic_merge(int *array, size_t size, int dir)
{
	size_t i, half;
	int temp;

	if (size > 1)
	{
		half = size / 2;
		printf("Merging [%lu/%lu] (%s):\n", (unsigned long)size, (unsigned long)size, dir == 1 ? "UP" : "DOWN");
		print_array(array, size);
		for (i = 0; i < half; i++)
		{
			if ((array[i] > array[i + half]) == dir)
			{
				temp = array[i];
				array[i] = array[i + half];
				array[i + half] = temp;
			}
		}
		bitonic_merge(array, half, dir);
		bitonic_merge(array + half, half, dir);
	}
}
/**
 * bitonic_sort_recursive - Recursively performs bitonic sort
 * @array: The array
 * @size: The size of the array
 * @dir: The direction (1 for ascending, 0 for descending)
 */
static void bitonic_sort_recursive(int *array, size_t size, int dir)
{
	size_t half;

	if (size > 1)
	{
		half = size / 2;
		bitonic_sort_recursive(array, half, 1);
		bitonic_sort_recursive(array + half, half, 0);
		bitonic_merge(array, size, dir);
	}
}
/**
 * bitonic_sort - Sorts an array of integers using Bitonic sort
 * @array: The array
 * @size: The size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	bitonic_sort_recursive(array, size, 1);
}
