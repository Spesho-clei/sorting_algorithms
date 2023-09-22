#include "sort.h"
#include <stdio.h>
#include <stdlib.h>


/**
 * merge - Merges two subarrays.
 * @array: The array to be sorted.
 * @temp: Temporary array to hold the merged subarrays.
 * @left: Left index.
 * @mid: Middle index.
 * @right: Right index.
 */
void merge(int *array, int *temp, int left, int mid, int right)
{
	int i, j, k;

	printf("Merging...\n[left]: ");
	print_array(array + left, mid - left);

	printf("[right]: ");
	print_array(array + mid, right - mid);

	for (i = left, j = mid, k = 0; i < mid && j < right; k++)
	{
		if (array[i] < array[j])
		{
			temp[k] = array[i];
			i++;
		}
		else
		{
			temp[k] = array[j];
			j++;
		}
	}

	while (i < mid)
	{
		temp[k] = array[i];
		i++;
		k++;
	}

	while (j < right)
	{
		temp[k] = array[j];
		j++;
		k++;
	}

	for (i = 0, k = left; k < right; i++, k++)
		array[k] = temp[i];

	printf("[Done]: ");
	print_array(temp, right - left);
}

/**
 * top_down_merge_sort - Recursive function to perform merge sort.
 * @array: The array to be sorted.
 * @temp: Temporary array to hold the merged subarrays.
 * @left: Left index.
 * @right: Right index.
 */
void top_down_merge_sort(int *array, int *temp, int left, int right)
{
	int mid;

	if (right - left <= 1)
		return;

	mid = (left + right) / 2;
	top_down_merge_sort(array, temp, left, mid);
	top_down_merge_sort(array, temp, mid, right);
	merge(array, temp, left, mid, right);
}

/**
 * merge_sort - Initiates the merge sort.
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;

	temp = malloc(sizeof(int) * size);

	if (temp == NULL)
		return;

	top_down_merge_sort(array, temp, 0, size);

	free(temp);
}
