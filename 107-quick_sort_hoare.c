#include <stdio.h>
#include "sort.h"

/* Function prototype for print_array */
void print_array(const int *array, size_t size);

/* Function prototype for hoare_partition */
int hoare_partition(int *array, int lo, int hi, size_t size);

/* Function prototype for qsh_helper */
void qsh_helper(int *array, int lo, int hi, size_t size);

/**
 * quick_sort_hoare - sorts an array of integers in ascending order
 *                     using the Quick sort algorithm with the Hoare
 *                     partition scheme
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	qsh_helper(array, 0, size - 1, size);
}

/**
 * qsh_helper - recursive helper function for quick_sort_hoare
 * @array: array to sort
 * @lo: lowest index of partition to sort
 * @hi: highest index of partition to sort
 * @size: size of the array
 */
void qsh_helper(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo < hi)
	{
		p = hoare_partition(array, lo, hi, size);
		qsh_helper(array, lo, p, size);
		qsh_helper(array, p + 1, hi, size);
	}
}

/**
 * hoare_partition - partitions an array using the Hoare partition scheme
 * @array: array to partition
 * @lo: lowest index of partition to sort
 * @hi: highest index of partition to sort
 * @size: size of the array
 *
 * Return: index of the pivot element
 */
int hoare_partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[lo];
	int i = lo - 1;
	int j = hi + 1;
	int tmp;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		print_array(array, size);
	}
}
