#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	try {
		Bureaucrat	a("a", 1);
		Bureaucrat	b = a;
		Form f("f", 1);

		std::cout << f << std::endl;
		a.signForm(f);
		std::cout << f << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
