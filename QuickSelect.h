#ifndef QUICKSELECT_H
#define QUICKSELECT_H

template<typename T>
T& QuickSelect(T arr[], int k, int first, int last)
{
	//Given an array of T and a kth index, find the element of kth index as if
	//the array was sorted.
	if (first == last)
		return arr[first];
	
	int i = first;
	int j = last;
	int pivotIndex = (last + first)/2;
	auto pivot = arr[pivotIndex];

	auto tmp = pivot;
	while (i < j)
	{
		//QuickSort parition and swap
		while (arr[i] < pivot)
			++i;
		while (arr[j] > pivot)
			--j;
		if ( i < j)
		{
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;	
		}
	}

	if (k <= pivotIndex) 
		QuickSelect(arr, k, first, pivotIndex);
	else if (k > pivotIndex)
		QuickSelect(arr, k, pivotIndex + 1, last);
		
	return arr[k];
}

#endif
