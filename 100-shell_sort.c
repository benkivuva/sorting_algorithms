#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm with Knuth sequence
 * @array: the array to be sorted
 * @size: the size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int temp;

	/* Calculate the initial gap using Knuth sequence */
	while (gap < size / 3)
		gap = gap * 3 + 1;

	/* Start the sorting process */
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;

			/* Perform insertion sort within the subarray */
			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}

			array[j] = temp;
		}

		/* Update the gap using Knuth sequence */
		gap = (gap - 1) / 3;

		/* Print the array after each pass (optional) */
		print_array(array, size);
	}
}
