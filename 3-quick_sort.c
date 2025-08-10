#include "sort.h"

/**
 * swap_ints - swaps two integers in an array
 * @a: pointer to first integer
 * @b: pointer to second integer
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	if (a == b)
		return;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - partitions the array using the Lomuto scheme
 * @array: the array to partition
 * @low: starting index of the partition
 * @high: ending index (pivot) of the partition
 * @size: size of the array (for print_array)
 *
 * Return: the index of the pivot element after partition
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap_ints(&array[i], &array[j]);
			if (i != j)
				print_array(array, size);
		}
	}
	swap_ints(&array[i + 1], &array[high]);
	if (i + 1 != high)
		print_array(array, size);

	return (i + 1);
}

/**
 * quick_sort_recursive - recursive quick sort function
 * @array: array to sort
 * @low: starting index
 * @high: ending index
 * @size: size of the array (for printing)
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, p - 1, size);
		quick_sort_recursive(array, p + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 *              using the Quick sort algorithm (Lomuto partition)
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
