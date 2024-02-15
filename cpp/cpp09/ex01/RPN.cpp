#include "RPN.hpp"

void p_error(std::string content)
{
    std::cerr << content << std::endl;
    exit(1);
}

int static stringToInt(std::string &str) {
    std::istringstream iss(str);
    int num;
    iss >> num;
    return num;
}

std::string static intToString(int num) {
    std::stringstream ss;
    ss << num;
    return ss.str();
}

void RPN::cal (char &op)
{
    if (stk.size() < 2)
        p_error("Error");
    int num1 = stringToInt(stk.top());
    stk.pop();
    int num2 = stringToInt(stk.top());
    stk.pop();
    if (op == '+')
        stk.push(intToString(num1 + num2));
    else if (op == '-')
        stk.push(intToString(num2 - num1));
    else if (op == '*')
        stk.push(intToString(num1 * num2));
    else if (op == '/')
        stk.push(intToString(num2 / num1));
}

RPN::RPN(char *input)
{
    while (*input)
    {     
        if (*input == ' ')
        {
            input++;
            continue;
        }
        else if (std::isdigit(*input))
            stk.push(std::string(1,*input));
        else if (*input == '+' || *input == '-' || *input == '*' ||*input == '/')
            cal(*input);
        input++;
    }
    std::cout << stk.top() << std::endl;
}

RPN::~RPN( void ) {}
