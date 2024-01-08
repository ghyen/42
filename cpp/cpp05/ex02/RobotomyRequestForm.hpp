#pragma once
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <time.h>

class RobotomyRequestForm : public AForm {
private:
    
public:
    void execute(Bureaucrat const & executor) const;
	RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm &ref);
    RobotomyRequestForm(std::string name);
    RobotomyRequestForm &operator=(const RobotomyRequestForm& ref);
	~RobotomyRequestForm( void );
};
