#include <iostream>
#include <type_traits>

int set(int *number, int pos) {
  if (pos > 31) {return -1;}
  int mask =  1 << pos;
  *number = *number | mask;
  return 0;
}

int unset(int *number, int pos) {
  if (pos > 31) {return -1;}
  int mask = 1 << pos;
  mask = ~mask;
  *number = *number & mask;
  return 0;
}

int main () {
  int number = 6;
  set(&number, 0);
  std::cout << number << std::endl;
  unset(&number, 0);
  std::cout << number << std::endl;
  return 0;
}

