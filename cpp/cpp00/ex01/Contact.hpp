#include "Contact.hpp"

class Contact {
private:
    //멤버변수
	char *first_name;
	char *last_name;
	char *nickname;
	char *phone_number;
	char *darkest_secret;

public:
    //메소드
    void get_first_name();
	void get_last_name();
	void get_nickname();
	void get_phone_number();
	void get_darkest_secret();
	void set_first_name();
	void set_last_name();
	void set_nickname();
	void set_phone_number();
	void set_darkest_secret();
};