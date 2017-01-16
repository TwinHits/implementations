#include "QuickSort.h"
#include "CStringCompare.h" 

/*******************
The algorithm for solving anagrams is to sort the strings and compare them to one another. Alternatively, you can count up the number of each characters and if both maps of counts are the same, then they are anagrams.
********************/

bool Anagram(char* first, char* second, int size)
{
		QuickSort(first, 0, size-1);
		QuickSort(second, 0, size-1);
			
		return CStringCompare(first, second);
}
