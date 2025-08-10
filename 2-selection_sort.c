#include "sort.h"

/**
 * selection_sort - that sorts an array of integers
 * @array: array
 * @size: size of array
 *
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_indx;
	int temp;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min_indx = 1;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array [min_indx])
				min_indx = j;
		}
		if (min_indx != j)
		{
			temp = array[i];
			array[i] = array[min_indx];
			array[min_indx] = temp;

			print_array(array, size);
		}
	}
}
