#include <stdio.h>

int parity_check(int number) {
  int parity = 1;
  while (number != 0 ){
    parity ^= (number & 1);
    number = number >> 1;
  }
  return parity;
}

int main () {
  printf("even parity: %d\n", parity_check(3));
  printf("odd parity: %d\n", parity_check(8));
}
