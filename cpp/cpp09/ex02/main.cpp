#include "PmergeMe.hpp"
#include <sstream>
#include <string>

int main(int argc, char **argv)
{
  std::vector<int> input;

    for(int i = 1; i < argc; i++)
    {
        std::stringstream ss(argv[i]);
        int value;
        ss >> value;
        if (value < 0)
        {
            std::cout << "Error" << std::endl;
            return 1;
        }
        input.push_back(value);
    }
    PmergeMe obj(input);
    return 0;
}
