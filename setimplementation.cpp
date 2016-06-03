#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

class Set {
	public:
		Set(std::vector<int> ints);
		bool Contains(int i);
		static Set* Intersection(Set* A, Set* B);
		std::string Print();
		std::vector<int> members;	
		bool operator==(Set& B);
		Set operator+=(const Set& rhs);
	private:
		int size;
};

Set::Set(std::vector<int> ints) 
{
	members = ints;
	std::sort(members.begin(), members.end());
	int x;
	for (auto i = members.begin(); i != members.end(); ++i)
	{
		if (x == *i)
		{
			members.erase(i); 
			i = i - 1;
		}
		else
			x = *i;
	}
}

bool Set::Contains(int i)
{
	if (find(members.begin(), members.end(), i) != members.end())
	{
		return true;
	}
	
	return false;
}

bool Set::operator==(Set& B) 
{
    return (this->members == B.members) && (B.members == this->members);
}

Set Set::operator+=(const Set& rhs)
{
	std::vector<int> ret = this->members;
	for (auto i = rhs.members.begin(); i != rhs.members.end(); i++)
		members.push_back(*i);
	return *this;
}	

Set operator+(Set lhs, const Set& rhs)
{
	lhs += rhs;		
	return Set(lhs.members);		
}

Set operator*(Set lhs, Set rhs) 
{
	std::vector<int> ret;
	for (auto i = lhs.members.begin(); i != lhs.members.end(); ++i)
	{
		for (auto x = rhs.members.begin(); x != rhs.members.end(); ++x)
		{
			if (*i == *x)
				ret.push_back(*i);
		}		
	}
	return Set(ret);
}

std::string Set::Print()
{
	std::string ret;
	
	ret += "{ ";
	for (auto i = members.begin(); i < members.end(); ++i)
	{
		ret += std::to_string(*i);
		ret += ", ";
	}
	ret += "}";

	return ret;
}

int main()
{
	std::vector<int> A = {1,1,3,4,6,7,8,9,1,2,3,4,5,6,7,8,9};
	std::vector<int> B = {11, 9, 3, 4, 6, 77, 8, 12, 23, 34};

	Set setA(A);
	Set setB(B);		
	
	std::cout << setA.Print() << std::endl;
	std::cout << setB.Print() << std::endl;

	std::cout << setA.Contains(1) << std::endl;
	std::cout << setB.Contains(1) << std::endl;
	
	if (setA == setB)
		std::cout << "equal" << std::endl;
	Set setC = setA + setB;

	std::cout << setC.Print() << std::endl;

	Set setD = setA * setB;

	std::cout << setD.Print() << std::endl;
}
