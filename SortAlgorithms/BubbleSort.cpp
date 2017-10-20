#include "stdafx.h"

void BubbleSort(int* arr, int size)
{
	bool checker = false;		// the sorting ends if there are no swaps in one go
	while (checker != true)
	{
		checker = true;
		for (int i = 0; i<size - 1; ++i)		// compare the values two by two and swap if neccessary
		{
			if (arr[i] > arr[i + 1])
			{
				int tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				checker = false;
			}
		}
	}
}