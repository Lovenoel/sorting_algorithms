/* 3-quick_sort.c */

#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using
 *              the Quick sort algorithm.
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort_recursive(array, 0, size - 1, size);
}

/**
 * quicksort_recursive - Recursively sorts an array of
 * integers using the Quick sort algorithm.
 * @array: The array to be sorted
 * @low: The starting index of the partition to be sorted
 * @high: The ending index of the partition to be sorted
 * @size: Number of elements in @array
 */
void quicksort_recursive(int *array, int low, int high, size_t size)
{
    int partition_index;

    if (low < high)
    {
        partition_index = lomuto_partition(array, low, high, size);

        quicksort_recursive(array, low, partition_index - 1, size);
        quicksort_recursive(array, partition_index + 1, high, size);
    }
}

/**
 * lomuto_partition - Implements the Lomuto partition scheme for Quick sort.
 *
 * @array: The array to be sorted
 * @low: The starting index of the partition to be sorted
 * @high: The ending index of the partition to be sorted
 * @size: Number of elements in @array
 *
 * Return: The partition index
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot, i, j, temp;

    pivot = array[high];
    i = low - 1;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            if (i != j)
                print_array(array, size);
        }
    }

    temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    if (i + 1 != high)
        print_array(array, size);

    return (i + 1);
}
