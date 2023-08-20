#include <iostream>

class Contact {
private:
    //멤버변수
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

public:
    //메소드
    std::string get_first_name();
	std::string get_last_name();
	std::string get_nickname();
	std::string get_phone_number();
	std::string get_darkest_secret();
	void set_first_name(const std::string& fname);
	void set_last_name(const std::string& lname);
	void set_nickname(const std::string& nname);
	void set_phone_number(const std::string& pnum);
	void set_darkest_secret(const std::string& secret);
};