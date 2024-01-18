#include "easyfind.hpp"
#include <iostream>
#include <deque>

int	main(void)
{
	std::deque<int> a;

	for (int i = 0; i < 10; i++)
		a.push_back(i);
	
	std::deque<int>::iterator it = easyfind(a, 4);

	if (it == a.end())
	{
		std::cout << "not found" << std::endl;
	}
	else
	{
		std::cout << "index is " << it - a.begin() << std::endl;
	}
	return 0;
}
