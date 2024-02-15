#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	try
	{
		if (argc == 1)
			return 1;
		BitcoinExchange btc(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
