# ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

#include <iostream>

class IMateriaSource {
private:

public:
    virtual ~IMateriaSource() {}
    virtual void learnMateria(AMateria*) = 0;
    virtual AMateria* createMateria(std::string const & type) = 0;

    IMateriaSource();
    IMateriaSource(const IMateriaSource&IMateriaSource);
    IMateriaSource&operator=(const IMateriaSource& IMateriaSource);
    ~IMateriaSource( void );
};

#endif
