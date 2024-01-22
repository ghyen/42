#pragma once
#include <iostream>
#include <exception>
#include <stack>

template <typename T>

class PmergeMe : public std::stack<T> {
	private:
		PmergeMe(void) {};
    public:
		PmergeMe() {std::vector<int> input};
        ~PmergeMe(void) {};
        PmergeMe(const PmergeMe &ref) {*this = ref;};
        PmergeMe& operator=(const PmergeMe& ref)
        {
            *this = ref;
            return *this;
        };
};
