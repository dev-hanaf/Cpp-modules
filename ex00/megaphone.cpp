#include <iostream>
#include <cstring>

int main(int ac, char** av) {
  int i = 1;
  
  if (ac == 1)
    return (1);
  
  while (i < ac)
  {
    for(size_t j=0; j < strlen(av[i]); j++)
      std::cout << (char)toupper(av[i][j]);
    if (i < ac - 1)
      std::cout << " ";
    i++;
  }
  std::cout << std::endl;
  return 0;
}
