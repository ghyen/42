// #include "MutantStack.hpp"

// int main() {
//     MutantStack<int> mstack;
//     mstack.push(5);
//     mstack.push(17);
//     std::cout << mstack.top() << std::endl;
//     mstack.pop();
//     std::cout << mstack.size() << std::endl;
//     mstack.push(3);
//     mstack.push(5);
//     mstack.push(737);
//     //[...]
//     mstack.push(0);
//     MutantStack<int>::iterator it = mstack.begin();
//     MutantStack<int>::iterator ite = mstack.end();
//     ++it;
//     --it;
//     while (it != ite)
//     {
//       std::cout << *it << std::endl;
//       ++it;
//     }
//     std::stack<int> s(mstack);
//     return 0;
// }

#include <iostream>
#include <list>
#include <iomanip>
#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	std::list<int> list;

	std::cout << std::setw(10) << "stack";
	std::cout << std::setw(10) << "list" << std::endl;

	mstack.push(5);
	mstack.push(17);

	list.push_back(5);
	list.push_back(17);

	std::cout << std::setw(10) << mstack.top();
	std::cout << std::setw(10) << list.back() << std::endl;

	mstack.pop();
	list.pop_back();

	std::cout << std::setw(10) << mstack.size();
	std::cout << std::setw(10) << list.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::list<int>::iterator it2 = list.begin();

	++it;
	--it;
	++it2;
	--it2;
	while (it != ite)
	{
		std::cout << std::setw(10) << *it;
		std::cout << std::setw(10) << *it2 << std::endl;
		++it;
		++it2;
	}
	std::stack<int> s(mstack);
	while (!s.empty()) {
		std::cout << std::setw(10) << s.top();
		std::cout << std::setw(10) << list.back() << std::endl;
		s.pop();
		list.pop_back();
	}
	return 0;
}
