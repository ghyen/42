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
    std::cout << "debug : " << low << std::endl;
    return low;
}

void PmergeMe::binarysearch_insert(std::vector<int> &arr, int needle, int needle_idx)
{
    std::cout << "before insert" << std::endl;
    printArray(arr);
    std::cout << "needle : " << needle << " needle_idx : " << needle_idx << std::endl;

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
    // for (size_t i = 0; i < subchain.size(); i++)
    // {
    //     //sorted의 값 순서대로 메인의 짝을 기준으로 서브체인 찾아서 정렬하자
    //     //서브 체인의 짝을 메인 체인에서 찾는다 해당 벨류가 sorted의 몇 인덱스인지 찾는다
    //     std::vector<int>::iterator it = std::find(mainchain.begin(), mainchain.end(), tmp[i]);
    //     //std::vector<int>::iterator it1 = std::find(sorted.begin(), sorted.end(), tmp[i]);
    //     if (i == 0)
    //         sorted.insert(sorted.begin(), subchain[it - mainchain.begin()]);
    //     else if (i == subchain.size() - 1)
    //         binarysearch_insert(sorted, subchain[it - mainchain.begin()], (i*2) -1);
    //     else
    //         binarysearch_insert(sorted, subchain[it - mainchain.begin()], (i*2));
    // }

    for (size_t k = 0; k < jacobsthal.size(); k++)
    {
        if (k == 0)
        {
            std::cout << "k is 0" << std::endl;
            std::vector<int>::iterator it = std::find(mainchain.begin(), mainchain.end(), tmp[0]);
            std::cout << "subchain[it - mainchain.begin()] is " << subchain[it - mainchain.begin()] <<  std::endl;
            sorted.insert(sorted.begin(), subchain[it - mainchain.begin()]);
            printArray(sorted);
            continue;
        }
        size_t i = jacobsthal[k];
        size_t until = jacobsthal[k - 1];
        
        std::cout<<"i : "<< i <<"  unitl : " << until << std::endl;
        while (i > until)
        {
            if (i > subchain.size())
            {
                std::cout << "berak:: subchain is :" << std::endl;
                printArray(subchain);
                i--;
                continue;;
            }
            std::cout << "i is : " << i << " mainchainsize is : " << mainchain.size() << std::endl;
            // if (i > mainchain.size())
            // {
            //     std::cout << "berak:: mainchain is :" << std::endl;
            //     printArray(mainchain);
            //     i--;
            //     continue;
            // }
            std::vector<int>::iterator it = std::find(mainchain.begin(), mainchain.end(), tmp[i - 1]);
            std::cout << "mainchain is : " << std::endl;
            printArray(mainchain);
            std::cout << "tmp[i - 1] is : " << tmp[i - 1] << std::endl;
            std::cout << "k is : " << k << " idx is : " << i << "  idx val is : " << *it << std::endl;
            if (!*it)
            {
                std::cout << "*it is 0 : " << std::endl;
                binarysearch_insert(sorted, subchain[i - 1], sorted.size());
            }
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
    printArray(jacobsthal);
    std::vector<int> ret = solve(input);
    printArray(ret);
    if (std::is_sorted(ret.begin(), ret.end())) {
        std::cout << "The sorted vector is: ";
        std::cout << std::endl;
    } else {
        std::cout << "The vector is not sorted." << std::endl;
    }
}
