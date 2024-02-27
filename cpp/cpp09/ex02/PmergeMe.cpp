#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

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

std::vector<int> static generateJacobsthalSequence(int n)
{
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

int binarySearch(std::vector<int> arr, int target, int idx)
{
    int low = 0;
    int high = idx;
    int mid;

    while(low < high)
    {
        mid = ((low + high) / 2) + 1;

        if (arr[0] > target)
            return 0;
        else if (arr[mid] < target && arr[mid + 1] > target)
            return mid + 1;
        else if (arr[mid] > target && arr[mid - 1] < target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    std::cout << "debug : " << low << std::endl;
    return low;
}

void PmergeMe::binarysearch_insert(std::vector<int> &arr, int needle, int needle_idx)
{
    std::cout << "before insert" << std::endl;
    printArray(arr);
    std::cout << "needle : " << needle << " needle_idx : " << needle_idx << std::endl;
    int idx = binarySearch(arr, needle, needle_idx);
    
    arr.insert(arr.begin() + idx, needle);
    std::cout << "after insert" << std::endl;
    printArray(arr);
}

std::vector<int> PmergeMe::solve(std::vector<int> &input)
{
    std::vector<int> mainchain;
    std::vector<int> subchain;
    std::vector<int> sorted;

    if (input.size() == 1)
    {
        std::cout << "top of recursive" << std::endl;
        return input;
        // int big = input[0] > input[1] ? input[0] : input[1];
        // int small = input[0] < input[0] ? input[1] : input[0];
        // sorted.push_back(small);
        // sorted.push_back(big);
        // printArray(sorted);
        // return sorted;
    }

    for (size_t i = 0; i < input.size() / 2; i++)
    {
        int big = input[i] > input[input.size()/2 + i] ? input[i] : input[input.size()/2 + i];
        int small = input[i] < input[input.size()/2 + i] ? input[i] : input[input.size()/2 + i];
        mainchain.push_back(big);
        subchain.push_back(small);
    }
    if (input.size() % 2 == 1)
            subchain.push_back(input.back());

    std::cout << "maincain" << std::endl;
    printArray(mainchain);
    std::cout << "subcain" << std::endl;
    printArray(subchain);

    sorted = solve(mainchain);

    std::vector<int> tmp = sorted;

    // bainary search to insert
    for (size_t i = 0; i < subchain.size(); i++)
    {
        //sorted의 값 순서대로 메인의 짝을 기준으로 서브체인 찾아서 정렬하자
        //서브 체인의 짝을 메인 체인에서 찾는다 해당 벨류가 sorted의 몇 인덱스인지 찾는다
        std::vector<int>::iterator it = std::find(mainchain.begin(), mainchain.end(), tmp[i]);
        //std::vector<int>::iterator it1 = std::find(sorted.begin(), sorted.end(), tmp[i]);
        if (i == 0)
            sorted.insert(sorted.begin(), subchain[it - mainchain.begin()]);
        else if (i == subchain.size() - 1)
            binarysearch_insert(sorted, subchain[it - mainchain.begin()], (i*2) -1);
        else
            binarysearch_insert(sorted, subchain[it - mainchain.begin()], (i*2));
    }

    for (int k = 1; k < jacobsthal.size(); k++)
    {
        for (int i = jacobsthal[k]; i < jacobsthal[i - 1]; i--)
        {
            
        }
    }
    return sorted;
}

PmergeMe::PmergeMe(std::vector<int> &input)
{
    jacobsthal = generateJacobsthalSequence(input.size());
    std::vector<int> ret = solve(input);
    printArray(ret);
    if (std::is_sorted(ret.begin(), ret.end())) {
        std::cout << "The sorted vector is: ";
        std::cout << std::endl;
    } else {
        std::cout << "The vector is not sorted." << std::endl;
    }
     printArray(jacobsthal);
}
