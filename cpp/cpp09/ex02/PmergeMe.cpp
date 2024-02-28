#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

std::vector<int> static generateJacobsthalSequence(int n)
{
    std::vector<int> sequence;
    std::vector<int> ret;
    int next_term;

    sequence.push_back(0);
    sequence.push_back(1);

    for (int i = 2; i < n; ++i)
    {
        next_term = sequence[i - 1] + sequence[i - 2] * 2; // 야콥스탈 수열의 규칙
        sequence.push_back(next_term);
        if (next_term > n)
            break;
    }
    for (size_t i = 2; i < sequence.size() - 1; ++i) // 앞에 두항 빼기
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
        mid = ((low + high) / 2);

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
    return low;
}

void binarysearch_insert(std::vector<int> &arr, int needle, int needle_idx)
{
    if (arr.size() == 1)
    {
        if (arr[0] > needle)
            arr.insert(arr.begin(), needle);
        else
            arr.insert(arr.begin() + 1, needle);    
    }
    else
    {
        int idx = binarySearch(arr, needle, needle_idx);
        arr.insert(arr.begin() + idx, needle);
    }
}

std::vector<int> PmergeMe::solve(std::vector<int> &input)
{
    std::vector<int> mainchain;
    std::vector<int> subchain;
    std::vector<int> sorted;

    if (input.size() == 1)
        return input;

    for (size_t i = 0; i < input.size() / 2; i++)
    {
        int big = input[i] > input[input.size()/2 + i] ? input[i] : input[input.size()/2 + i];
        int small = input[i] < input[input.size()/2 + i] ? input[i] : input[input.size()/2 + i];
        mainchain.push_back(big);
        subchain.push_back(small);
    }
    if (input.size() % 2 == 1)
        subchain.push_back(input.back());

    sorted = solve(mainchain);

    std::vector<int> tmp = sorted;
    for (size_t k = 0; k < jacobsthal.size(); k++)
    {
        if (k == 0)
        {
            std::vector<int>::iterator it = std::find(mainchain.begin(), mainchain.end(), tmp[0]);
            sorted.insert(sorted.begin(), subchain[it - mainchain.begin()]);
            continue;
        }
        size_t i = jacobsthal[k];
        size_t until = jacobsthal[k - 1];
        
        while (i > until)
        {
            if (i > subchain.size())
            {
                i--;
                continue;;
            }
            std::vector<int>::iterator it = std::find(mainchain.begin(), mainchain.end(), tmp[i - 1]);
            if (!*it)
                binarysearch_insert(sorted, subchain[i - 1], sorted.size());
            else
            {
                if (i == 0)
                    sorted.insert(sorted.begin(), subchain[it - mainchain.begin()]);
                else if (i == subchain.size() - 1)
                    binarysearch_insert(sorted, subchain[it - mainchain.begin()], sorted.size());
                else
                    binarysearch_insert(sorted, subchain[it - mainchain.begin()], sorted.size());
            }
            i--;
        }
    }
    return sorted;
}


int binarySearch(std::deque<int> arr, int target, int idx)
{
    int low = 0;
    int high = idx;
    int mid;

    while(low < high)
    {
        mid = ((low + high) / 2);

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
    return low;
}

void binarysearch_insert(std::deque<int> &arr, int needle, int needle_idx)
{
    if (arr.size() == 1)
    {
        if (arr[0] > needle)
            arr.insert(arr.begin(), needle);
        else
            arr.insert(arr.begin() + 1, needle);    
    }
    else
    {
        int idx = binarySearch(arr, needle, needle_idx);
        arr.insert(arr.begin() + idx, needle);
    }
}

std::deque<int> PmergeMe::solve(std::deque<int> &input)
{
    std::deque<int> mainchain;
    std::deque<int> subchain;
    std::deque<int> sorted;

    if (input.size() == 1)
        return input;

    for (size_t i = 0; i < input.size() / 2; i++)
    {
        int big = input[i] > input[input.size()/2 + i] ? input[i] : input[input.size()/2 + i];
        int small = input[i] < input[input.size()/2 + i] ? input[i] : input[input.size()/2 + i];
        mainchain.push_back(big);
        subchain.push_back(small);
    }
    if (input.size() % 2 == 1)
        subchain.push_back(input.back());

    sorted = solve(mainchain);

    std::deque<int> tmp = sorted;
    for (size_t k = 0; k < jacobsthal.size(); k++)
    {
        if (k == 0)
        {
            std::deque<int>::iterator it = std::find(mainchain.begin(), mainchain.end(), tmp[0]);
            sorted.insert(sorted.begin(), subchain[it - mainchain.begin()]);
            continue;
        }
        size_t i = jacobsthal[k];
        size_t until = jacobsthal[k - 1];
        
        while (i > until)
        {
            if (i > subchain.size())
            {
                i--;
                continue;;
            }
            std::deque<int>::iterator it = std::find(mainchain.begin(), mainchain.end(), tmp[i - 1]);
            if (!*it)
                binarysearch_insert(sorted, subchain[i - 1], sorted.size());
            else
            {
                if (i == 0)
                    sorted.insert(sorted.begin(), subchain[it - mainchain.begin()]);
                else if (i == subchain.size() - 1)
                    binarysearch_insert(sorted, subchain[it - mainchain.begin()], sorted.size());
                else
                    binarysearch_insert(sorted, subchain[it - mainchain.begin()], sorted.size());
            }
            i--;
        }
    }
    return sorted;
}

PmergeMe::PmergeMe(std::vector<int> &input)
{
    jacobsthal = generateJacobsthalSequence(input.size());
    jacobsthal.push_back(input.size());
    clock_t	start_time = clock();
	std::vector<int> vec_ret = solve(input);
    
	clock_t	end_time = clock();
	vector_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

    std::deque<int> deque_input;
    std::vector<int>::iterator it;
    for (it = input.begin(); it != input.end(); ++it)
        deque_input.push_back(*it);
    start_time = clock();
    std::deque<int> deq_ret = solve(deque_input);
    end_time = clock();
	deque_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC;

    std::cout << "Before: " << to_string(input) << '\n'
	          << "After : " << to_string(vec_ret) << '\n'
			  << std::fixed
			  << "Time to process a range of " << input.size()
	          << " elements with std::vector : " << vector_time << " us" << '\n'
			  << "Time to process a range of " << input.size()
	          << " elements with std::deque  : " << deque_time << " us" << '\n';
}
