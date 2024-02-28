#pragma once
#include <iostream>
#include <exception>
#include <stack>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <vector>

template <typename T>
std::string to_string(const T& c)
{
	std::stringstream s;
	typename T::const_iterator it = c.begin();
	const typename T::const_iterator end = c.end();

	s << *it; ++it;
	for (; it != end; ++it)
		s << " " << *it;
	return s.str();
}

class PmergeMe {
private:
    PmergeMe(const PmergeMe &ref) {*this = ref;};
    PmergeMe& operator=(const PmergeMe& ref);
	std::vector<int> jacobsthal;
	double vector_time;
	double deque_time;
public:
	void printMatrix(std::vector< std::vector<int> > &input);
	PmergeMe(void);
	~PmergeMe(void) {};
	PmergeMe(std::vector<int> &input);
	std::vector<int> solve(std::vector<int> &input);
	std::deque<int> solve(std::deque<int> &input);
	//void binarysearch_insert(std::vector<int> &arr, int needle, int needle_idx);
};
