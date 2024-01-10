#pragma once
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreatiohnForm : public AForm {
private:
    ShrubberyCreatiohnForm &operator=(const ShrubberyCreatiohnForm& ref);
public:
    void execute(Bureaucrat const & executor) const;

	ShrubberyCreatiohnForm();
    ShrubberyCreatiohnForm(std::string name);
    ShrubberyCreatiohnForm(const ShrubberyCreatiohnForm &ref);
	~ShrubberyCreatiohnForm( void );
    class FileOpenException : public std::exception
    {
        const char* what() const throw();
    };
};
