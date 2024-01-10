#pragma once
#include <string>

class Bureaucrat;

class AForm {
protected:
    const std::string name;
    bool sign;
    const int signStandard;
    const int execStandard;

private:
    AForm &operator=(const AForm& AForm);
    AForm(const AForm &AForm);
public:
    const std::string getName( void ) const;
    int getsignStandard( void ) const;
    int getexecStandard( void ) const;
    bool getSigned( void ) const;
    void beSigned(const Bureaucrat &bureaucrat);
    virtual void execute(Bureaucrat const &executor) const = 0;

    AForm();
    AForm(std::string name, const int signStandard, const int execStandard);
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
    class NotSignedException : public std::exception
    {
        const char* what() const throw();
    };
};

std::ostream &operator<<(std::ostream &os, const AForm &bureaucrat);
