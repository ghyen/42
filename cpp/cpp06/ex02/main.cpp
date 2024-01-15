#include "Serializer.hpp"

int	main()
{
	Data *d = new (Data);
	if (d == Serializer::deserialize(Serializer::serialize(d)))
		std::cout << "good" << std::endl;
	else
		std::cout << "bad" << std::endl;
}
