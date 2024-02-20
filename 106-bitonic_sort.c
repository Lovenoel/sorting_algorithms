#include "sort.h"
#include <stdio.h>

/**
 * bitonic_compare - Compares two elements in ascending order.
 *
 * @dir: The sorting direction (1 for ascending, 0 for descending).
 * @array: The array containing the elements.
 * @i: The index of the first element.
 * @j: The index of the second element.
 */
void bitonic_compare(int dir, int *array, size_t i, size_t j)
{
    if ((dir && array[i] > array[j]) || (!dir && array[i] < array[j]))
    {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

/**
 * bitonic_merge - Merges two bitonic sequences in ascending order.
 *
 * @dir: The sorting direction (1 for ascending, 0 for descending).
 * @array: The array containing the elements.
 * @low: The starting index of the first sequence.
 * @cnt: The size of the sequences to be merged.
 */
void bitonic_merge(int dir, int *array, size_t low, size_t cnt)
{
    if (cnt > 1)
    {
        size_t k = cnt / 2;
        size_t i;

        for (i = low; i < low + k; i++)
        {
            bitonic_compare(dir, array, i, i + k);
        }

        bitonic_merge(dir, array, low, k);
        bitonic_merge(dir, array, low + k, k);
    }
}

/**
 * bitonic_sort_recursive - Sorts a bitonic sequence recursively.
 *
 * @dir: The sorting direction (1 for ascending, 0 for descending).
 * @array: The array containing the elements.
 * @low: The starting index of the bitonic sequence.
 * @cnt: The size of the bitonic sequence.
 */
void bitonic_sort_recursive(int dir, int *array, size_t low, size_t cnt)
{
    if (cnt > 1)
    {
        size_t k = cnt / 2;

        printf("Merging [%lu/%lu] (%s):\n", cnt, cnt, (dir ? "UP" : "DOWN"));
        print_array(array + low, cnt);

        bitonic_sort_recursive(1, array, low, k);
        bitonic_sort_recursive(0, array, low + k, k);
        bitonic_merge(dir, array, low, cnt);
    }
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using the Bitonic sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    printf("Merging [%lu/%lu] (UP):\n", size, size);
    print_array(array, size);

    bitonic_sort_recursive(1, array, 0, size);
}
