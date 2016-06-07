#ifndef QUICKSORT_H
#define QUICKSORT_H

template<typename T>
void QuickSort(T arr[], int first, int last)
{
	int i = first;
	int j = last;
	T tmp;
	T pivot = arr[(first+last)/2];

	while (i <= j)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j)
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	}

	if (first < last)
	{ 
		if (first < j)
			QuickSort(arr, first, j);
		if (i < last)
			QuickSort(arr, i, last);
	}
}

#endif
