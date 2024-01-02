#pragma once
#include "Bureaucrat.hpp"

class Form {
private:
    const std::string name;
    bool sign;
    const int grade;

public:
    std::string getName( void ) const;
    int getGrade( void ) const;
    bool getSigned( void ) const;
    void beSigned(const Bureaucrat &bureaucrat);

    Form();
    Form(std::string name, int grade);
    Form(const Form &Form);
    Form &operator=(const Form& Form);
    virtual ~Form( void );

    class GradeTooHighException : public std::exception
    {
        public:
            const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        public:
            const char* what() const throw();
    };

    class CanNotCopyException : public std::exception
    {
        public:
            const char* what() const throw();
    };

    class alreadySignedException : public std::exception
    {
        public:
            const char* what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const Form &bureaucrat);
