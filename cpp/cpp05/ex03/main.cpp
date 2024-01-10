#include "Intern.hpp"

// void a()
// {
// 	system("leaks Form");
// }

int	main()
{
	// atexit(a);
	try {
		Bureaucrat	a("a", 26);
		Intern gkwon;
		AForm *tmp = gkwon.makeForm("robotomy reques", "Bender");
		std::cout << *tmp << std::endl;
		a.signForm(*tmp);
		a.executeForm(*tmp);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
