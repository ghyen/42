#pragma once
#include <iostream>
#include <exception>
#include <stack>
#include <algorithm>


class PmergeMe {
private:
    PmergeMe(const PmergeMe &ref) {*this = ref;};
    PmergeMe& operator=(const PmergeMe& ref);
	std::vector<int> jacobsthal;
public:
	void printMatrix(std::vector< std::vector<int> > &input);
	PmergeMe(void);
	~PmergeMe(void) {};
	PmergeMe(std::vector<int> &input);
	std::vector<int> solve(std::vector<int> &input);
	int find_pairval(std::vector<int> from, int find);
	void binarysearch_insert(std::vector<int> &arr, int needle, int needle_idx);
};
