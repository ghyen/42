# pragma once
#include "AMateria.hpp" //Character 에서도 해당 내용 참조, 상호참조문제 : 전방 선언 필요

class ICharacter {
public:
    virtual ~ICharacter() {}
    virtual std::string const & getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};
