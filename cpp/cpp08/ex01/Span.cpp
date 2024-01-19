#include "Span.hpp"

Span::Span(unsigned int n) : myVector(std::vector<int>()), maxN(n) {}

Span::Span(const Span& ref)
{
    for (unsigned int i = 0; i < ref.myVector.size(); i++)
        myVector[i] = ref.myVector[i];
    std::reverse(myVector.begin(), myVector.end());
}

Span::~Span() {myVector.clear();}

Span& Span::operator=(const Span& ref)
{
	this->~Span();
    new (this) Span(ref);
    return *this;
}

void Span::addNumber(int num)
{
    if (myVector.size() == maxN)
        throw std::exception();
    myVector.push_back(num);
}

int Span::shortestSpan()
{
    if (myVector.size() <= 2)
        throw std::exception();
    std::vector<int> tmp = myVector;
    std::sort(tmp.begin(), tmp.end());
    std::vector<int>::iterator n1;
    std::vector<int>::iterator n2;
    long min = INT_MAX;
    for (n1 = tmp.begin(); n1 != tmp.end(); n1++)
        for (n2 = n1 + 1; n2 != tmp.end(); n2 ++)
            if (min > *n2 - *n1)
                min = *n2 - *n1;
    return static_cast<int>(min);
}

int Span::longestSpan()
{
    if (myVector.size() <= 2)
        throw std::exception();
    return *std::max_element(myVector.begin(), myVector.end()) - *std::min_element(myVector.begin(), myVector.end());
}

void Span::printElement()
{
    unsigned int i = 0;
    for (std::vector<int>::iterator it = myVector.begin(); it != myVector.end(); it++, i++)
        std::cout << "index " << i << " is " << *it << std::endl;
}

void Span::addMany(unsigned int n)
{
    for (unsigned int i = 0; i < n; i++)
    {
        addNumber(i);
    }
}
