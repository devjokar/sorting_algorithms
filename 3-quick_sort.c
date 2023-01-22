#include "sort.h"

/**
 * _qsort - helper for the quick_sort function
 * @a: input arrray
 * @start: index for the first element
 * @end: index for the last element
 * @size: size of the array
 */
void _qsort(int *a, int start, int end, int size)
{
	int p, w, i;
	int tmp;

	if (start < end)
	{
		p = end;
		w = start;
		for (i = start; i < end; i++)
		{
			if (a[i] < a[p])
			{
				if (i != w)
				{
					tmp = a[i];
					a[i] = a[w];
					a[w] = tmp;
					print_array(a, size);
				}
				w++;
			}
		}
		if (w != p && a[w] != a[p])
		{
			tmp = a[w];
			a[w] = a[p];
			a[p] = tmp;
			print_array(a, size);
		}
		_qsort(a, start, w - 1, size);
		_qsort(a, w + 1, end, size);
	}
}

/**
 * quick_sort - sorts an arra of integers in ascending order
 * using the quick sort algorithm
 *
 * @array: input arrray
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	_qsort(array, 0, size - 1, size);
}
