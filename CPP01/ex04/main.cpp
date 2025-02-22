#include <cstddef>
#include <cstring>
#include <fstream>
#include <iostream>

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cout << "Bad arguments" << std::endl;
        return 1;
    }

    std::ifstream inputFile(av[1]);
    if (!inputFile.is_open())
    {
        std::cerr << "Error: Could not open the file!" << std::endl;
        return 1;
    }

    std::string file = av[1];
    file.append(".replace");
    std::ofstream newFile(file.c_str());
   
    if (!newFile.is_open())
    {
        std::cerr << "Error: Could not create the file!" << std::endl;
        return 1;
    }

    size_t len = strlen(av[2]);
    std::string line;
    while (std::getline(inputFile, line)) {      
        size_t index = line.find(av[2], 0);
        while (index != std::string::npos)
        {
            line.erase(index, len);
            line.insert(index, av[3]);
            index = line.find(av[2], index);
        }
        newFile <<  line << std::endl;
    }    
    inputFile.close();
    newFile.close();
    return 0;
}
