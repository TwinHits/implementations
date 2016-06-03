#include <iostream>
#include <string>
#include <cctype>

using namespace std;

enum action { ENCRYPT, DECRYPT };
string crypt(action type, int nrails, string data) 
{
	//make an int called cyclesize 2 times (nrails -1)
	int cyclesize = 2*(nrails-1);
	//You can turn a 
	string ret(data);
	int pos = 0, i, a;
	int & rpos = type ? i : pos, & dpos = type ? pos : i;
	for	(int rail = 0; rail < nrails; ++rail) 
	{
		for	(i = rail, a = 2*rail; i < data.length(); a = cyclesize - a, i += a) 
		{
			if (a==cyclesize) continue;
			ret[rpos] = data[dpos];
			++pos;
		}
	}
	return ret;
}

int main()
{
	string data;
	action act;
	int nrails;
	cin >> data >> nrails;
	if (data == "enc") act = ENCRYPT;
	else if (data == "dec") act = DECRYPT;
	else 
	{
		cout << "Unknown action.\n";
		return 1;
	}

	while (isspace(cin.peek())) cin.ignore();
	getline(cin, data);

	cout << crypt(act, nrails, data);
	return 0;
}
