#include "stdafx.h"

void GnomeSort(int* arr, int size)
{
	int pos = 0;
	while (pos != size)
	{
		if (pos == 0 || arr[pos - 1] <= arr[pos])		// when at 1st pos and if the pair is sorted, go one step forward
			pos++;

		else if (arr[pos - 1] > arr[pos])				// otherwise swap the values and go one step backwards
		{
			int tmp = arr[pos];
			arr[pos] = arr[pos - 1];
			arr[pos - 1] = tmp;
			pos--;
		}
	}
}