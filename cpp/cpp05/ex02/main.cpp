#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

// void a()
// {
// 	system("leaks Form");
// }

int	main()
{
	//atexit(a);
	try {
		Bureaucrat	a("a", 26);
		Bureaucrat b = a;
		std::cout << b << std::endl;
		RobotomyRequestForm rForm("r");
		ShrubberyCreatiohnForm sForm("s");
		PresidentialPardonForm pForm("p");
		a.signForm(sForm);
		a.executeForm(sForm);
		a.signForm(rForm);
		a.executeForm(rForm);
		a.signForm(pForm);
		a.executeForm(pForm);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
