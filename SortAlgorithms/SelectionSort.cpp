#include "stdafx.h"

void SelectionSort(int* arr, int size)		
{											
	for (size_t j = 0; j < size - 1; ++j)
	{
		int minIndex = j;
		for (size_t i = j + 1; i < size - 1; ++i)
		{
			if (arr[minIndex] > arr[i])
			{
				minIndex = i;
			}

		}
		if (minIndex != j)			// if the minimal element is not in the correct spot, we swap
		{
			int tmp = arr[j];
			arr[j] = arr[minIndex];
			arr[minIndex] = tmp;
		}
	}
}