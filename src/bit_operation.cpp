#include <iostream>

int main(){
  int state = 0b01010101;

  std::cout << (state >> 0 & 1) << std::endl;
  std::cout << (state >> 1 & 1) << std::endl;
  std::cout << (state >> 2 & 1) << std::endl;
  std::cout << (state >> 3 & 1) << std::endl;

  return 0;
}
