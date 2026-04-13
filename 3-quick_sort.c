#include "sort.h"

/**
 * lomuto_partition - partitions array using Lomuto scheme
 * @array: pointer to the array
 * @low: starting index
 * @high: ending index (pivot)
 * @size: size of the full array
 *
 * Return: index of the pivot after partition
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot;
	int temp;
	int i;
	int j;

	pivot = array[high];
	i = low - 1;
	j = low;

	while (j < high)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
		j++;
	}
	if (i + 1 != high)
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort - recursive quicksort helper
 * @array: pointer to the array
 * @low: starting index
 * @high: ending index
 * @size: size of the full array
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, low, high, size);
		quicksort(array, low, pivot - 1, size);
		quicksort(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: pointer to the array to sort
 * @size: size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, (int)size - 1, size);
}
