#pragma once
#include <iostream>

class Bureaucrat {
protected:
    const std::string name;
    int grade;

public:
    std::string getName( void ) const;
    int getGrade( void ) const;

    Bureaucrat();
    Bureaucrat(const Bureaucrat &Bureaucrat);
    Bureaucrat &operator=(const Bureaucrat& Bureaucrat);
    virtual ~Bureaucrat( void );
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);