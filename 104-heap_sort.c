#include "sort.h"

/**
 * sift_down - Restores the heap property after removing the root element.
 *
 * @array: The array to be transformed into a heap
 * @size: The size of the array
 * @root: The index of the root of the heap
 * @end: The last index of the heap
 */
void sift_down(int *array, size_t size, size_t root, size_t end)
{
    size_t max, child, left_child, right_child;

    while ((left_child = 2 * root + 1) <= end)
    {
        right_child = left_child + 1;
        max = left_child;

        if (right_child <= end && array[right_child] > array[left_child])
            max = right_child;

        if (array[root] < array[max])
        {
            /* Swap root and max child */
            int temp = array[root];
            array[root] = array[max];
            array[max] = temp;

            print_array(array, size);
            root = max;
        }
        else
        {
            break;
        }
    }
}

/**
 * heapify - Builds a max heap from the array.
 *
 * @array: The array to be transformed into a heap
 * @size: The size of the array
 */
void heapify(int *array, size_t size)
{
    ssize_t i;

    for (i = size / 2 - 1; i >= 0; i--)
        sift_down(array, size, i, size - 1);
}

/**
 * heap_sort - Sorts an array of integers in ascending order using the Heap sort algorithm.
 *
 * @array: The array to be sorted
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
    size_t end;

    if (array == NULL || size < 2)
        return;

    heapify(array, size);

    for (end = size - 1; end > 0; end--)
    {
        /* Swap root and last element of the heap */
        int temp = array[0];
        array[0] = array[end];
        array[end] = temp;

        print_array(array, size);

        sift_down(array, size, 0, end - 1);
    }
}
