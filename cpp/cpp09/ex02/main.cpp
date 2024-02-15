#include "PmergeMe.hpp"
#include <sstream>
#include <string>

static void printArray(std::vector<int> &ref)
{
	std::cout << "length: " << ref.size() << std::endl;
	for (unsigned int i = 0; i < ref.size(); i++)
        std::cout << "[" << i << "]: " << ref[i] << std::endl;
}

int main(int argc, char **argv)
{
  std::vector<int> input;

    for(int i = 1; i < argc; i++)
    {
        std::stringstream ss(argv[i]);
        int value;
        ss >> value;
        input.push_back(value);
    }
    printArray(input);
    PmergeMe obj;
    obj.solve(input);
  
    return 0;
}
