#include <iostream>

int find_max(int array[], int length) {
  if (length <= 0) {
    return -1;
  }
  int max = array[0];
  for (int i = 1; i < length; i++) {

    if (array[i] > max) {
      max = array[i];
    }
  }
  return max;
}

int main() {
  int array [] = {1, 2, 3, 4, 5, 6, 7, 8, 19, 10};
  int max;
  if ((max = find_max (array, 10)) > 0) {
    std::cout << max << std::endl;
  }
  else {
    std::cout << "Array is empty" << std::endl;
  }
  return 0;
}
