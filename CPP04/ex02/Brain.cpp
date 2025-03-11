#include "Brain.hpp"


Brain::Brain()
{
    std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &obj)
{
    std::cout << "Brain copy constructor called" << std::endl;
    for(int i=0; i < 100; i++)
    {
        this->ideas[i] = obj.ideas[i];
    }
}

Brain& Brain::operator=(const Brain &obj)
{
    std::cout << "Brain copy assignemt operator called" << std::endl;
    if (this != &obj )
    {
        for(int i=0; i < 100; i++)
        {
            this->ideas[i] = obj.ideas[i];
        }
    }
    return  *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}


// std::string *Brain::getIdeas()
// {
//     return ideas;
// }

// std::string Brain::getIdea(int index)
// {
//     if (index < 100 && index >= 0)
//         return this->ideas[index];
//     return "";
// }

// void Brain::setIdea(int index, const std::string &idea)
// {
//     if (index < 100 && index >= 0)
//     {
//         this->ideas[index] = idea;
//         std::cout << "the idea "<< idea << " added succefuly into the array of ideas" << std::endl;
//         return;
//     }
//     std::cout << "Bad index" << std::endl;
// }