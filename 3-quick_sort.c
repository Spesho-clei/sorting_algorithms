#include "sort.h"
void swap(int *a, int *b);
	
/**
 * swap - swap two integers
 * @a: pointer to first integer
 * @b: pointer to second integer
 */
void swap(int *a, int *b)
{
	int tmp = *a;

	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Lomuto partition scheme for quicksort
 * @array: array to be partitioned
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 * Return: pivot index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * lomuto_qsort - recursive function for quicksort
 * @array: array to be sorted
 * @low: starting index
 * @high: ending index
 * @size: size of the array
 */
void lomuto_qsort(int *array, int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = lomuto_partition(array, low, high, size);
		lomuto_qsort(array, low, pi - 1, size);
		lomuto_qsort(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	lomuto_qsort(array, 0, size - 1, size);
}
