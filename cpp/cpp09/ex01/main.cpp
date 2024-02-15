#include "RPN.hpp"

int	main(int argc, char **argv)
{
	try {
		if (argc == 2)
			RPN rpn(argv[1]);
		return 0;
	} catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}
	return 0;
}
