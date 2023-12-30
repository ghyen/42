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
    ~MateriaSource() override;

    void learnMateria(AMateria*) override;
    AMateria* createMateria(std::string const & type) override;
};
