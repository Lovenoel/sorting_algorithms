#include "sort.h"

/**
 * merge - Merges two sub-arrays of the array.
 *
 * @array: The array containing the sub-arrays to be merged
 * @temp: A temporary array used for merging
 * @left: The start index of the left sub-array
 * @mid: The end index of the left sub-array and start index of the right sub-array
 * @right: The end index of the right sub-array
 */
void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
    size_t i, j, k;

    printf("Merging...\n[left]: ");
    print_array(array + left, mid - left);
    printf("[right]: ");
    print_array(array + mid, right - mid);

    for (i = left, j = mid, k = 0; i < mid && j < right; k++)
    {
        if (array[i] < array[j])
            temp[k] = array[i++];
        else
            temp[k] = array[j++];
    }
    while (i < mid)
        temp[k++] = array[i++];

    while (j < right)
        temp[k++] = array[j++];

    for (i = left, k = 0; i < right; i++)
        array[i] = temp[k++];

    printf("[Done]: ");
    print_array(array + left, right - left);
}

/**
 * merge_sort_recursive - Recursively divides and merges the array.
 *
 * @array: The array to be sorted
 * @temp: A temporary array used for merging
 * @left: The start index of the sub-array
 * @right: The end index of the sub-array
 */
void merge_sort_recursive(int *array, int *temp, size_t left, size_t right)
{
    size_t mid;

    if (right - left > 1)
    {
        mid = (left + right) / 2;

        merge_sort_recursive(array, temp, left, mid);
        merge_sort_recursive(array, temp, mid, right);

        merge(array, temp, left, mid, right);
    }
}

/**
 * merge_sort - Sorts an array of integers in ascending order using the Merge sort algorithm.
 *
 * @array: The array to be sorted
 * @size: The size of the array
 */
void merge_sort(int *array, size_t size)
{
    int *temp;

    if (array == NULL || size < 2)
        return;

    temp = malloc(size * sizeof(int));
    if (temp == NULL)
        return;

    merge_sort_recursive(array, temp, 0, size);

    free(temp);
}
