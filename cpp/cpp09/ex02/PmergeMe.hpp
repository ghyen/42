#pragma once
#include <iostream>
#include <exception>
#include <stack>

template <typename T>

class PmergeMe {
private:
	PmergeMe(void) {};
	~PmergeMe(void) {};
    PmergeMe(const PmergeMe &ref) {*this = ref;};
    PmergeMe& operator=(const PmergeMe& ref)
public:
	std::vector<int> &solve(std::vector<int> &input) {};
};
