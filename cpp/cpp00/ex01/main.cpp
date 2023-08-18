#include <iostream>
#include <cctype>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(void){
	int com;
	PhoneBook phonebook;

	while (1)
	{
		std::cout << "enter command\nadd : 1\nsearch : 2\nexit : 3" << std::endl;
		std::cin >> com;
		if (com == 1)
			phonebook.add_contact();
		else if (com == 2)
			phonebook.search_contact();
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