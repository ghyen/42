#include "iter.hpp"

int	main()
{
	char char_arr[] = {'h', 'i', '4', '2', '!'};

	std::cout << "Char: ";
	iter(char_arr, sizeof(char_arr) / sizeof(char), print<char>);
	std::cout << '\n';

	int	int_arr[] = {1, 2, 3, 4, 5};

	std::cout << "Int: ";
	iter(int_arr, sizeof(int_arr) / sizeof(int), print<int>);
	std::cout << '\n';

	float float_arr[] = {1.0, 2.0, 3.0, 4.0, 5.0};

	std::cout << "Float: ";
	iter(float_arr, sizeof(float_arr) / sizeof(float), print<float>);
	std::cout << '\n';
	return 0;
}
