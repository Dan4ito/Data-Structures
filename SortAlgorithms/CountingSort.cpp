#include "stdafx.h"

void CountingSort(int* arr, int size, int k)	// used for a numbers within an interval, k is number of different values
{
	int* result = new int[k];
	for (int m = 0; m < k; ++m) {			// creating an array with size k, and initialise all elements to 0
		result[m] = 0;
	}
	for (int i = 0; i<size; ++i) {
		result[arr[i]]++;					// filling the interval array

	}
	int indexer = 0;
	for (int i = 0; i<k; ++i) {				// replacing our initial array with the corret values
		while (result[i]>0)
		{
			arr[indexer] = i;
			indexer++;
			result[i]--;
		}

	}
	delete[] result;		// deallocate memory
}