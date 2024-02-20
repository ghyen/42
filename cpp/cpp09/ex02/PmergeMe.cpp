#include "PmergeMe.hpp"

void PmergeMe::printMatrix(std::vector< std::vector<int> > &input)
{
    for (size_t i = 0; i < input.size(); ++i) {
        for (size_t j = 0; j < input[i].size(); ++j) {
            std::cout << input[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

static void printArray(std::vector<int> &ref)
{
	std::cout << "length: " << ref.size() << std::endl;
	for (unsigned int i = 0; i < ref.size(); i++)
        std::cout << "[" << i << "]: " << ref[i] << std::endl;
}

bool compare(const std::vector<int>& a, const std::vector<int>& b) {
    return a[0] < b[0]; // 0번째 인덱스를 기준으로 오름차순 정렬
}

std::vector<int> static generateJacobsthalSequence(int n) {
    std::vector<int> sequence;
    std::vector<int> ret;

    sequence.push_back(0);
    sequence.push_back(1);

    for (int i = 2; i < n; ++i)
    {
        int next_term = sequence[i - 1] + sequence[i - 2] * 2; // 야콥스탈 수열의 규칙
        if (next_term > n)
            break;
        sequence.push_back(next_term);
    }
    for (int i = 2; i < n - 2; ++i) // 앞에 두항 빼기
        ret.push_back(sequence[i]);
    return ret;
}

std::vector<int> PmergeMe::solve(std::vector<int> &input)
{
    std::vector<int> half;
    std::vector<int> half;
    for (size_t idx = 0; idx < input.size() / 2; idx++)
        half.push_back(input[idx]);

    if (half.size() != 2)
        solve(half);
    else
        return std::sort(half.begin(), half.end(), compare);


    
}

void PmergeMe::fordJohson(std::vector<int> input, )
{

};

PmergeMe::PmergeMe(std::vector<int> &input)
{
    jacobsthal = generateJacobsthalSequence(input.size());
    solve(input);
};
