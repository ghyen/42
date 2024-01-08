#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	try {
		Bureaucrat	a("a", 2);
		RobotomyRequestForm rForm;
		PresidentialPardonForm *pForm = new PresidentialPardonForm();
		a.signForm(*pForm);
		a.executeForm(*pForm);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
