#pragma once
#include <iostream>
#include <exception>
#include <stack>
#include <algorithm>


class PmergeMe {
private:
    PmergeMe(const PmergeMe &ref) {*this = ref;};
    PmergeMe& operator=(const PmergeMe& ref);
public:
	std::vector<int> sorted;
	void printMatrix(std::vector< std::vector<int> > &input);
	PmergeMe(void)
	~PmergeMe(void) {};
	PmergeMe(std::vector<int> &input);
	std::vector<int> solve(std::vector<int> &input);
};
