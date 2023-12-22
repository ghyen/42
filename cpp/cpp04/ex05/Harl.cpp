#include "Harl.hpp"

Harl::Harl(void) {}

Harl::~Harl(void) {}

void Harl::complain(std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*func[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    for (int i = 0; i < 4; i++)
        if (level == levels[i])
            (this->*func[i])();
}
