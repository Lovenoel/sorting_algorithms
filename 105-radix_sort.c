#include "sort.h"
#include <stdlib.h>

/**
 * getMax - Returns the maximum value in an array.
 *
 * @array: The array to find the maximum value in.
 * @size: The size of the array.
 *
 * Return: The maximum value in the array.
 */
int getMax(int *array, size_t size)
{
    int max = array[0];
    size_t i;

    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
    }

    return (max);
}

/**
 * countSort - Sorts an array using counting sort based on a specific digit.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @exp: The current digit to sort by (exponential value).
 */
void countSort(int *array, size_t size, int exp)
{
    int *output = malloc(sizeof(int) * size);
    int count[10] = {0};
    size_t i;

    if (output == NULL)
        return;

    for (i = 0; i < size; i++)
        count[(array[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = size - 1; i < SIZE_MAX; i--)
    {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    for (i = 0; i < size; i++)
        array[i] = output[i];

    print_array(array, size);
    free(output);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using the Radix sort algorithm.
 *
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
    int max = getMax(array, size);
    size_t exp;

    if (array == NULL || size < 2)
        return;

    for (exp = 1; max / exp > 0; exp *= 10)
    {
        countSort(array, size, exp);
    }
}
