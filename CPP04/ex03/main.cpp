#include "AMateria.hpp"
#include "Character.hpp"
# include "Cure.hpp"
#include "ICharacter.hpp"
# include "Ice.hpp"

int main()
{
    AMateria*   ice = new Ice();
    AMateria*   cure = new Cure();

    // AMateria*   ice2 = ice->clone();

    delete ice ;
    delete cure;
    // if ()


}