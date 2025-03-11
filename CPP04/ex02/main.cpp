#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
  const Animal* j = new Dog();
  const Animal* i = new Cat();
  delete j;//should not create a leak
  delete i;
  
  Animal *animals[4];

  animals[0] = new Cat("siamo");
  animals[1] = new Cat("3alal");
  animals[2] = new Dog("pitbul");
  animals[3] = new Dog("malinwa");

  
  for (int i=0; i < 4; i++)
  {
      delete animals[i];
  }
  
  return 0;
}