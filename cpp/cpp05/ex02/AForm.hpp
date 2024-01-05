#pragma once
#include "Bureaucrat.hpp"

class AForm {
private:
    const std::string name;
    const int grade;
    bool sign;

public:
    std::string getName( void ) const;
    int getGrade( void ) const;
    bool getSigned( void ) const;
    void beSigned(const Bureaucrat &bureaucrat);
    virtual void excute(Bureaucrat const &executor) = 0;

    AForm();
    AForm(std::string name, int grade);
    AForm(const AForm &AForm);
    AForm &operator=(const AForm& AForm);
    virtual ~AForm( void );

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

std::ostream &operator<<(std::ostream &os, const AForm &bureaucrat);
