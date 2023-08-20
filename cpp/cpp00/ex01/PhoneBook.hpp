#include "Contact.hpp"

class PhoneBook {
private:
    //멤버변수
    Contact contacts[8];
    int index;
    int pointer;

public:
    //메소드
    void phonebook();
    void add_contact();
	void search_contact(int index);
	void print_contact();
};
