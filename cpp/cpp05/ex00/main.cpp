#include "Bureaucrat.hpp"

int	main()
{
	try {
		Bureaucrat	a(150, "a");
		Bureaucrat	b(1, "b");


		// a.downGrade();
		a.upGrade();
		std::cout << a << std::endl;
		// b.upGrade();
		b.downGrade();
		std::cout << b << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}