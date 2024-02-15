#pragma once
#include <iostream>
#include <stack>
#include <exception>
#include <sstream>

class RPN {
private:
    std::stack<std::string> stk;
    RPN &operator=(const RPN& RPN);
    void cal(char &op);
public:
    RPN();
    ~RPN( void );
    void printElement();
    void addMany(unsigned int n);
    void addNumber(int num);
    int shortestSpan();
    int longestSpan();
    RPN(char *input);
};
