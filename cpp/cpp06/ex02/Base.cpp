#include "Base.hpp"

Base::~Base() {}

Base *generate(void)
{
    srand(time(NULL));
    int ret = rand() % 3;
	if (ret == 0)
		return new A();
    else if (ret == 1)
        return new B();
	else
		return new C();
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
		std::cout << "pointer is A\n";
	if (dynamic_cast<B*>(p))
		std::cout << "pointer is B\n";
	if (dynamic_cast<C*>(p))
		std::cout << "pointer is C\n";
}

void identify(Base &p)
{
    try {
        dynamic_cast<A&>(p);
        std::cout << "A\n";
        return ;
    } catch (const std::exception &e()) {
    }
    try {
        dynamic_cast<B&>(p);
        std::cout << "B\n";
        return ;
    } catch (const std::exception &e()) {
    }
    try {
        dynamic_cast<C&>(p);
        std::cout << "C\n";
        return ;
    } catch (const std::exception &e()) {
    }
}
