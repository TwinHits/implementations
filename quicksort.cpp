#include <iostream>

void quickSort(int arr[], int first, int last)
{
	int i = first;
	int j = last;
	int tmp;
	int pivot = arr[(first+last)/2];

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
			quickSort(arr, first, j);
		if (i < last)
			quickSort(arr, i, last);
	}
}

int main()
{
	int arr[] = {5,4,3,2,1,23,1,123,14,43,56,54,37,81,18};
	quickSort(arr, 0, 14);
	for (int i = 0; i < 15; i++)
	{
		std::cout << arr[i] << std::endl;
	}
}
