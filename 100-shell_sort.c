#include <stddef.h>
#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using
 *		the Shell sort algorithm.
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1;

	while (gap < size)
	{
		gap = gap * 3 + 1;
	}
	gap /= 3;

	while (gap > 0)
	{
		size_t i;
		for (i = gap; i < size; ++i)
		{
			int temp = array[i];
			size_t j = i;

			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}
		gap /= 3;
	}
}
