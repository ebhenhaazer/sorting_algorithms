#include "sort.h"
#include <stdio.h>

/**
 * swap_ints - change two integers in ascending or descending order
 * @a: pointer to the first integer
 * @b: pointer to the second integer
 */
void swap_ints(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bitonic_merge - merge bitonic sequences
 * @array: array
 * @size: size of the array
 * @start: starting index
 * @seq: sequence length
 * @flow: 1 for ascending order, 0 for descending order
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq, char flow)
{
	size_t i, j;
	int temp;

	if (seq <= 1)
		return;

	i = start;
	j = start + seq / 2;

	if (flow)
	{
		printf("Merging [%lu/%lu] (UP):\n", seq, size);
		print_array(&array[i], seq);
	}
	else
	{
		printf("Merging [%lu/%lu] (DOWN):\n", seq, size);
		print_array(&array[i], seq);
	}

	for (; i < start + (seq / 2); i++, j++)
	{
		if (flow == (array[i] > array[j]))
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}

	bitonic_merge(array, size, start, seq / 2, flow);
	bitonic_merge(array, size, start + seq / 2, seq / 2, flow);

	if (flow)
	{
		printf("Result [%lu/%lu] (UP):\n", seq, size);
		print_array(&array[start], seq);
	}
	else
	{
		printf("Result [%lu/%lu] (DOWN):\n", seq, size);
		print_array(&array[start], seq);
	}
}

/**
 * bitonic_seq - recursively create bitonic sequences
 * @array: array
 * @size: size of the array
 * @start: starting index
 * @seq: sequence length
 * @flow: 1 for ascending order, 0 for descending order
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char flow)
{
	if (seq <= 1)
		return;

	if (flow)
	{
		printf("Merging [%lu/%lu] (UP):\n", seq, size);
		print_array(&array[start], seq);
	}
	else
	{
		printf("Merging [%lu/%lu] (DOWN):\n", seq, size);
		print_array(&array[start], seq);
	}

	bitonic_seq(array, size, start, seq / 2, 1);
	bitonic_seq(array, size, start + seq / 2, seq / 2, 0);

	bitonic_merge(array, size, start, seq, flow);

	if (flow)
	{
		printf("Result [%lu/%lu] (UP):\n", seq, size);
		print_array(&array[start], seq);
	}
	else
	{
		printf("Result [%lu/%lu] (DOWN):\n", seq, size);
		print_array(&array[start], seq);
	}
}

/**
 * bitonic_sort - sort an array using the bitonic sort algorithm
 * @array: array
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	bitonic_seq(array, size, 0, size, 1);
}
