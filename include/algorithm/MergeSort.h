#ifndef MERGESORT_H
#define MERGESORT_H

//MergeSort is  O(n log n)
//Which is the same as QuickSort, but QuickSort has better space complexity and works better on many hardware sets.
//This implementation is careful to maintain relative order of identical elements
template <typename T>
void Merge(T arr[], int first, int mid, int last)
{
	int size = last - first + 1;
	T tmp[size];
	int k = 0;
	
	for (int i = first, j = mid + 1; i <= mid || j <= last;)
	{
		if (arr[i] < arr[j] && i <= mid)
		{
			tmp[k] = arr[i];
			++k;
			++i;
		}
		else if (arr[i] > arr[j] && j <= last)
		{
			tmp[k] = arr[j];
			++k;
			++j;
		}
		else if (i <= mid)
		{
			tmp[k] = arr[i];
			++k;
			++i;
		}
		else if (j <= last)
		{
			tmp[k] = arr[j];
			++k;
			++j;
		}
	}
	for (int l = 0; l < size; ++l)
	{
		arr[l+ first] = tmp[l];
	}
}

template <typename T>
void MergeSort(T arr[], int first, int last)
{
	//If the size of the array is one, return it. This is the base case. The array is inherently sorted.
	if (last - first + 1 != 1)
	{
		int mid = (first + last) / 2;
		//Split until the halves are sorted by virtue of being size ==1
		MergeSort(arr, first, mid);
		MergeSort(arr, mid+1, last);

		//Merge two sorted halves
		Merge(arr, first, mid, last);
	}
}

#endif
