#pragma once
#include <iostream>
#include <exception>

class Bureaucrat {
private:
    const std::string name;
    int grade;

public:
    std::string getName( void ) const;
    int getGrade( void ) const;
    void increseGrade();
    void decreseGrade();

    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &Bureaucrat);
    Bureaucrat &operator=(const Bureaucrat& Bureaucrat);
    virtual ~Bureaucrat( void );

    class GradeTooHighException : public std::exception
    {
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
        const char* what() const throw();
    };

    class CanNotCopyException : public std::exception
    {
        const char* what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);
