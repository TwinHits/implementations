#include "algorithm/IsSubstring.h"

//Is s2 a substring of s1?
bool IsSubstring(char* s1, char* s2)
{
	//waterbottle
	//tle
	for (int i = 0; s1[i] != '\0'; ++i)
	{
		if (s1[i] == s2[0])
		{
			for (int j = i, x = 0;; ++j, ++x)
			{
				if (s2[x] == '\0')
				   return true;
				else if (s1[j] != s2[x])
					break;	
			}
		}
	}	

	return false;
}
