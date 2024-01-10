#include "Bureaucrat.hpp"

int	main()
{
	try {
		Bureaucrat	a("a", 150);
		Bureaucrat	b("b", 1);


		//a.decreseGrade();
		a.increseGrade();
		std::cout << a << std::endl;
		//b.increseGrade();
		b.decreseGrade();
		std::cout << b << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
