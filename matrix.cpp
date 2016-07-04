#include <iostream>
#include <vector>

//Strassen's Subcubic Matrix Multiplication Algorithm

int main()
{
	std::vector<std::vector<int> > a = {{1,4,7,3},{2,5,8,2},{3,6,9,1},{1,5,6,7}};
	std::vector<std::vector<int> > b = {{5,6,3,7},{0,5,7,8},{2,1,8,9},{9,5,7,3}};

	for (auto i = a.begin(); i != a.end(); i++)
	{
		for (auto j = i->begin(); j != i->end(); j++)
		{
			std::cout << *j << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	for (auto i = b.begin(); i != b.end(); i++)
	{
		for (auto j = i->begin(); j != i->end(); j++)
		{
			std::cout << *j << " ";
		}
		std::cout << std::endl;
	}

}
