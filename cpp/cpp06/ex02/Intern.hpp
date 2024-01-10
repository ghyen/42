#pragma once
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
private:
    Intern(const Intern &Intern);
    Intern &operator=(const Intern& Intern);

public:
    AForm *makeForm(std::string formName, std::string targetForm);
    
    Intern();
    virtual ~Intern( void );

    class NotExistException : public std::exception
    {
        const char* what() const throw();
    };
};
