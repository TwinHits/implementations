#ifndef ANAGRAM_H
#define ANAGRAM_H

#include "QuickSort.h"

//The algorithm for solving anagrams is to sort the strings and compare them to one another. Alternatively, you can count up the number of each characters and if both maps of counts are the same, then they are anagrams.
//Doesn't work since you can't compare char*

bool Anagram(char* first, char* second, int size)
{
		QuickSort(first,0,size);
		QuickSort(second,0,size);
			
		return first == second;
}

#endif
