#pragma once
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <time.h>

class RobotomyRequestForm : public AForm {
private:
    RobotomyRequestForm(const RobotomyRequestForm &ref);
public:
    void execute(Bureaucrat const & executor) const;
    
	RobotomyRequestForm();
    RobotomyRequestForm(std::string name);
    RobotomyRequestForm &operator=(const RobotomyRequestForm& ref);
	~RobotomyRequestForm( void );
};
