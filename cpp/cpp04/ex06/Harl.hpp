# ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl {
private:
    void debug(void){std::cout << "[ DEBUG ]" << std::endl << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;};
    void info(void){std::cout << "[ INFO ]" << std::endl << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;};
    void warning(void){std::cout << "[ WARNING ]" << std::endl << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;};
    void error(void){std::cout << "[ ERROR ]" << std::endl << "This is unacceptable! I want to speak to the manager now." << std::endl;};

public:
    Harl(void);
    ~Harl(void);
    void complain(std::string level);
};

#endif
