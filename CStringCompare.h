#ifndef CSTRINGCOMPARE_H
#define CSTRINGCOMPARE_H

bool CStringCompare(char* first, char* second)
{
	int i = 0;
	char nullterm = '\n';

	while (first[i] != nullterm && second[i] != nullterm)
	{
		if (first[i] == second[i])
		{
			++i;
		}
		else 
		{
			return false;
		}	
	}
	return true;
}

#endif
