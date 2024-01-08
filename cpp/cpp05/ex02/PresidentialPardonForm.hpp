#pragma once
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
    
public:
    void execute(Bureaucrat const & executor) const;

	PresidentialPardonForm();
    PresidentialPardonForm(std::string name);
    PresidentialPardonForm(const PresidentialPardonForm &ref);
    PresidentialPardonForm &operator=(const PresidentialPardonForm& ref);
	~PresidentialPardonForm( void );
};
