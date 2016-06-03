#include <iostream>
#include <string>
#include <vector>

//I implemented merge sort!
//This algorithm is 6nlog^2n+6n
template <typename T>
std::vector<T> merge(std::vector<T>& v, const std::vector<T>& a, const std::vector<T>& b)
{
	//Make a vector for sorted stuff
	std::vector<T> result;
	for (auto i = a.begin(), j = b.begin(); result.size() != a.size() + b.size();)
	{
		//For each n in a and be, until the size of result == size of a + size of b
		//liberal use of != a.end() to handle odd sized vectors
		if (i != a.end() && *i <= *j)
		{
			result.push_back(*i);
			++i;
		}
		else if (j != b.end() && *j < *i)
		{
			result.push_back(*j);
			++j;
		}
		else if (i == a.end())
		{
			result.push_back(*j);
			++j;
		}
		else if (j == b.end())
		{
			result.push_back(*i);
			++i;
		}
	}
	//return new v
	v = result;
	return v;
}

template <typename T>
std::vector<T> MergeSort(std::vector<T>& v)
{
	//If the size of the vector is one, return it. This is the base case. The vector is inherently sorted.
	if (v.size() == 1)
		return v;

	auto middle = v.begin() + v.size()/2;
	std::vector<T> a(v.begin(), middle);
	std::vector<T> b(middle, v.end());

	//Merge sort until the halfs are sorted. Or, in the case of size == 1, inherently sorted.
	MergeSort(a);
	MergeSort(b);

	return merge(v, a, b);
}

//"Quadratic" means that is has an n^2 in it somewhere

int main()
{
	std::vector<int> v;

	v.push_back(512);
	v.push_back(125);
	v.push_back(772);
	v.push_back(231);
	v.push_back(212);
	v.push_back(2132);
	v.push_back(1312);
	v.push_back(1);
	v.push_back(1913);

	MergeSort(v);

	for (auto i : v)
	{
		std::cout << i << std::endl;
	}
}
