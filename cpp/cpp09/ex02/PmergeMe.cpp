#include "PmergeMe.hpp"

void PmergeMe::printMatrix(std::vector< std::vector<int> > &input)
{
    for (size_t i = 0; i < input.size(); ++i) {
        for (size_t j = 0; j < input[i].size(); ++j) {
            std::cout << input[i][j] << " ";
        }
        std::cout << std::endl;
    }
};

void PmergeMe::solve(std::vector<int> &input)
{
    for (size_t i = 0; i < input.size(); ++i) {
        std::cout << input[i] << " ";
    }
    std::cout << std::endl;

    for (int idx = 0; idx < input.size() / 2; idx += 2)
    {
        std::vector<int> tmp;
        if (input[idx] > input[idx + 1])
        {
            tmp.push_back(input[idx]);
            tmp.push_back(input[idx + 1]);
        }
        else
        {
            tmp.push_back(input[idx + 1]);
            tmp.push_back(input[idx]);
        }
        pairs.push_back(tmp);
    }
    if (input.size() % 2 == 1)
    {
        std::vector<int> tmp;
        tmp.push_back(input.back());
        pairs.push_back(tmp);
    }
    printMatrix(pairs);
};
