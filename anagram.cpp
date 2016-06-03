#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

//The algorithm for solving anagrams is to sort the strings and compare them to one another. Alternatively, you can count up the number of each characters and if both maps of counts are the same, then they are anagrams.
//
//Also, learn to read the instructions.

void anagram(const std::vector<std::string>& first_words, const std::vector<std::string>& second_words)
{
	for (auto i = first_words.begin(), j = second_words.begin(); i != first_words.end() && j != second_words.end(); ++i, ++j)
	{
		std::string s1 = *i;
		std::string s2 = *j;
		
		std::sort(s1.begin(), s1.end());
		std::sort(s2.begin(), s2.end());
		if (s1 == s2)
			std::cout << 1 << std::endl;
		else
			std::cout << 0 << std::endl;
	}
}

int main ()
{
	std::vector<std::string> first_words;
	first_words.push_back("iceman");
	first_words.push_back("bab");

	std::vector<std::string> second_words;
	second_words.push_back("cinema");
	second_words.push_back("aba");

	anagram(first_words, second_words);
}
