#include "Span.hpp"

int	main()
{
	try {
		//Span sp = Span(4);
		
		//sp.addNumber(6);
		//sp.addNumber(3);
		//sp.addNumber(17);
		//sp.addNumber(9);
		//sp.addNumber(11);
		//sp.printElement();
		
		//std::cout << sp.shortestSpan() << std::endl;
		//std::cout << sp.longestSpan() << std::endl;
		long _num = 100000;
		Span sp = Span(_num);
		sp.addMany(_num);
		sp.printElement();
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cout << "out of range" << std::endl;
	}
	return 0;
}
