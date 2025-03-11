#pragma once

#include <iostream>

class Brain
{
    private:
        std::string ideas[100];
    public:
    Brain();
    Brain(const Brain &);
    Brain& operator=(const Brain&);
    ~Brain();
    // std::string getIdea(int index);
    // void setIdea(int index, const std::string &idea);
};