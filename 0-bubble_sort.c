#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order
 *              using the Bubble sort algorithm.
 *
 * @array: Pointer to the unsorted array to be sorted.
 * @size:  The number of elements in the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;

				/* Print array after each swap */
				print_array(array, size);
			}
		}
	}
}
