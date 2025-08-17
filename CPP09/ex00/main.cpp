#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    try
    {

        BitcoinExchange btc;
        btc.fileExist(av[1]);
        btc.fetchFileData();
        // btc.diplayMap();
        btc.parseInput();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
