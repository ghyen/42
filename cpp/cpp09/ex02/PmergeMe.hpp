#pragma once
#include <iostream>
#include <exception>
#include <stack>

class PmergeMe {
private:
    PmergeMe(const PmergeMe &ref) {*this = ref;};
    PmergeMe& operator=(const PmergeMe& ref);
public:
	std::vector< std::vector<int> > pairs;
	void printMatrix(std::vector< std::vector<int> > &input);
	PmergeMe(void) {};
	~PmergeMe(void) {};
	void solve(std::vector<int> &input) {};
};
