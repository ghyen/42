#include "Base.hpp"

int	main()
{
	Base *rand = generate();
	identify(rand);
	identify(*rand);
}
