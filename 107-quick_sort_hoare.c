#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two elements in an array.
 *
 * @array: The array containing the elements.
 * @i: The index of the first element.
 * @j: The index of the second element.
 */
void swap(int *array, int i, int j)
{
    if (i != j)
    {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

/**
 * hoare_partition - Implements the Hoare partition scheme.
 *
 * @array: The array to be partitioned.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: The size of the array.
 *
 * Return: The index of the pivot after partitioning.
 */
int hoare_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1, j = high + 1;

    while (1)
    {
        do
        {
            i++;
        } while (array[i] < pivot);

        do
        {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return j;

        swap(array, i, j);
        print_array(array, size);
    }
}

/**
 * quicksort_hoare - Sorts an array of integers using the Quick sort algorithm
 *                   with the Hoare partition scheme.
 *
 * @array: The array to be sorted.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: The size of the array.
 */
void quicksort_hoare(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pivot_index = hoare_partition(array, low, high, size);

        quicksort_hoare(array, low, pivot_index, size);
        quicksort_hoare(array, pivot_index + 1, high, size);
    }
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using the
 *                    Quick sort algorithm with the Hoare partition scheme.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort_hoare(array, 0, size - 1, size);
}
