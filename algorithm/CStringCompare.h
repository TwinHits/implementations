#ifndef CSTRINGCOMPARE_H
#define CSTRINGCOMPARE_H

/** 
 *Currently fails because sometimes the arrays end with /377, the end of file terminator which doesn't make ANY SENSE.
 **/

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

#endif
