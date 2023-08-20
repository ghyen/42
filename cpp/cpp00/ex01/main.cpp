#include <iostream>
#include <cctype>
#include "PhoneBook.hpp"

int main(void){
	int com;
	int index;
	PhoneBook phonebook = PhoneBook();

	while (1)
	{
		std::cout << "enter command\nadd : 1\nsearch : 2\nexit : 3" << std::endl;
		std::cin >> com;
		if (com == 1)
			phonebook.add_contact();
		else if (com == 2)
		{
			phonebook.print_contact();
			std::cout << "enter index" << std::endl;
			std::cin >> index;
			phonebook.search_contact(index);
		}
		else if (com == 3)
		{
			std::cout << "exit" << std::endl;
			break;
		}
		else
			std::cout << "wrong command" << std::endl;
	}
    return 0;
}