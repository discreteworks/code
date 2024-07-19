#include <iostream>
#include <cmath>

void split_integer(int num, int size) {
  long divisor = pow (10, size - 1);
  while (num > 0) {
    std::cout << num/ divisor << "   ";
    num %= divisor;
    divisor /= 10;
  }
  std::cout << std::endl;
}

int main () {
  int num = 0;
  int size = 0;
  std::cout << "Enter number:";
  std::cin >> num;
  std::cout << "Enter number size(no of digits):";
  std::cin >> size;
  split_integer(num, size);
  return 0;
}
