#include "PhoneBook.hpp"
#include <iomanip>

void PhoneBook::phonebook(){
	index = 0;
	cnt = 0;
}

std::string truncate(const std::string& str, int width){
    if (static_cast<int>(str.length()) > width) {
        return str.substr(0, width).append(".");
    }
    return str;
}

bool nullCheck(std::string& str){
	if (str.empty() == true)
	{
		std::cout << "dose not allow empty value" << std::endl;
		return false;
	}
	return true;
}

void PhoneBook::add_contact(){
	if (index > 7)
		index %= 8;
	std::string temp_first_name;
	std::string temp_last_name;
	std::string temp_nickname;
	std::string temp_phone_number;
	std::string temp_darkest_secret;

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << "enter first name" << std::endl;
	std::getline(std::cin, temp_first_name);
	if (!nullCheck(temp_first_name))
		return;
	std::cout << "enter last name" << std::endl;
	std::getline(std::cin, temp_last_name);
	if (!nullCheck(temp_last_name))
		return;
	std::cout << "enter nickname" << std::endl;
	std::getline(std::cin, temp_nickname);
	if (!nullCheck(temp_nickname))
		return;
	std::cout << "enter phone number" << std::endl;
	std::getline(std::cin, temp_phone_number);
	if (!nullCheck(temp_phone_number))
		return;
	std::cout << "enter darkest secret" << std::endl;
	std::getline(std::cin, temp_darkest_secret);
	if (!nullCheck(temp_darkest_secret))
		return;
	contacts[index].set_first_name(temp_first_name);
	contacts[index].set_last_name(temp_last_name);
	contacts[index].set_nickname(temp_nickname);
	contacts[index].set_phone_number(temp_phone_number);
	contacts[index].set_darkest_secret(temp_darkest_secret);
	index++;
	cnt++;
}

void PhoneBook::search_contact(int _index){
	if (_index >= cnt || index < 0)
	{
		std::cout << "wrong index" << std::endl;
		return;
	}
	std::cout << "first name : " << contacts[_index].get_first_name() << std::endl;
	std::cout << "last name : " << contacts[_index].get_last_name() << std::endl;
	std::cout << "nickname : " << contacts[_index].get_nickname() << std::endl;
	std::cout << "phone number : " << contacts[_index].get_phone_number() << std::endl;
	std::cout << "darkest secret : " << contacts[_index].get_darkest_secret() << std::endl;
}

void PhoneBook::print_contact(){
	int i = 0;
	if (index == 0)
	{
		std::cout << "no contacts" << std::endl;
		return;
	}
	if (cnt > 7)
		cnt = 8;
	std::cout << "   index  |first name| last name|  nickname" << std::endl;
	while (i < cnt)
	{
		std::cout << std::setw(10) << std::right << i << "|";
		std::cout << std::setw(10) << std::right << truncate(contacts[i].get_first_name(), 9) << "|";
		std::cout << std::setw(10) << std::right << truncate(contacts[i].get_last_name(), 9) << "|";
		std::cout << std::setw(10) << std::right << truncate(contacts[i].get_nickname(), 9) << std::endl;
		i++;
	}
}