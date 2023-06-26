#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order
 *              using the Quick Sort algorithm with Lomuto partition scheme.
 *
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

/**
 * quick_sort_recursive - Recursive function for Quick Sort
 *
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements in the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, pivot - 1, size);
		quick_sort_recursive(array, pivot + 1, high, size);
	}
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick Sort
 *
 * @array: The array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Number of elements in the array
 *
 * Return: The final position of the pivot after partitioning
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, tmp;

	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap_elements(&array[i], &array[j]);
			print_array(array, size);
		}
	}

	swap_elements(&array[i + 1], &array[high]);
	print_array(array, size);

	return (i + 1);
}

/**
 * swap_elements - Swaps two elements in an array
 *
 * @a: Pointer to the first element
 * @b: Pointer to the second element
 */
void swap_elements(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
