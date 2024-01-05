#pragma once
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreatiohnForm : public AForm {
private:
    const int signStandard = 145;
    const int execStandard = 137;
    
public:
    void execute(Bureaucrat const & executor);

	ShrubberyCreatiohnForm();
    ShrubberyCreatiohnForm(std::string name);
    ShrubberyCreatiohnForm &operator=(const ShrubberyCreatiohnForm& SCForm);
	void ~AForm( void );
};
