#include "sort.h"

/**
 * sift_down - Repair the heap whose root element is at index 'start'
 * @array: Array to sort
 * @start: Start index of the heap
 * @end: End index of the heap
 * @size: Size of the array
 */
void sift_down(int *array, int start, int end, int size)
{
	int root = start;
	int child, swap, tmp;

	while (2 * root + 1 <= end)
	{
		child = 2 * root + 1;
		swap = root;
		if (array[swap] < array[child])
			swap = child;
		if (child + 1 <= end && array[swap] < array[child + 1])
			swap = child + 1;
		if (swap == root)
			return;
		tmp = array[root];
		array[root] = array[swap];
		array[swap] = tmp;
		print_array(array, size);
		root = swap;
	}
}

/**
 * heap_sort - Sorts an array of integers using heap sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i, tmp;

	for (i = (size / 2) - 1; i >= 0; i--)
		sift_down(array, i, size - 1, size);
	for (i = size - 1; i > 0; i--)
	{
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		print_array(array, size);
		sift_down(array, 0, i - 1, size);
	}
}
