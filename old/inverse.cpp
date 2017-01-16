#include <iostream>
#include <vector>

//Counting Inversions problem: Given array A of length N in some order. Compute the number of 'inversions'.
//Inversion: When array[i] > array[j]. A single number is greater than any of the next numbers, opposite of sorted
//Implement in terms of merge sort, this piggybacking strategy allows the algorithm to retain mergesort's O(nlog^n) complexity.

template<typename T>
std::vector<T> CountSplitInversions(std::vector<T>& v, const std::vector<T>& a, const std::vector<T>& b, int& count)
{
	//Make a vector for sorted stuff
	std::vector<T> result;
	for (auto i = a.begin(), j = b.begin(); result.size() != a.size() + b.size();)
	{
		//For each n in a and b, until the size of result == size of a + size of b
		//liberal use of != a.end() to handle odd sized vectors
		//if i > j, that is an inversion, so ++ the count by the num of remaining things in the subarray.
		//Doing this accounts for the inversions that would be passed over with ++J
		if (i != a.end() && *i <= *j)
		{
			result.push_back(*i);
			++i;
		}
		else if (j != b.end() && *j < *i)
		{
			result.push_back(*j);
			++j;
			count += (a.begin() + a.size() - i);
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
int CountInversions(std::vector<T>& v)
{
	static int count = 0;
	if (v.size() == 1)
		return 0;
	else 
	{
		auto middle = v.begin() + v.size()/2;
		std::vector<T> a(v.begin(), middle);
		std::vector<T> b(middle, v.end());

		CountInversions(a);
		CountInversions(b);
		CountSplitInversions(v, a, b, count);

		return count;
	}

}

int main()
{
	std::vector<int> inversions = {6,5,4,3,2,1};

	std::cout << CountInversions(inversions) << std::endl;
}
