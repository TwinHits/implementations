#include "CStringCompare.h"

bool CStringCompare(char* first, char* second) 
{
	while (*first == *second && *first != '\0')
	{
		if (*first != *second)
			return false;
		first++;
		second++;
	}

	if (*first != *second)
		return false;

	return true;
}
