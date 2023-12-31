#pragma once
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
    static const int mSize = 4;
	AMateria* mSlot[mSize];
public:
    MateriaSource();
    MateriaSource(const MateriaSource&MateriaSource);
    MateriaSource&operator=(const MateriaSource& MateriaSource);
    ~MateriaSource() ;

    void learnMateria(AMateria* m) ;
    AMateria* createMateria(std::string const & type) ;
};
