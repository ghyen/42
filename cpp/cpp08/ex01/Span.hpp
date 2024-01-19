#pragma once
#include <iostream>
#include <vector>
#include <exception>

class Span {
private:
    std::vector<int> myVector;
    unsigned int maxN;
    Span();
public:
    void printElement();
    void addMany(unsigned int n);
    void addNumber(int num);
    int shortestSpan();
    int longestSpan();
    Span(unsigned int n);
    Span(const Span &Span);
    Span &operator=(const Span& Span);
    ~Span( void );
};
