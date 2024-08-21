#include <iostream>

int find_max(int array[], int length) {
  if (length <= 0) {
    return -1;
  }
  int max_1 = array[0];
  int max_2 = array[length - 1];
  int i;
  int j;

  for (i = 1, j = length - 2; i < length; i++, j--) {

    if (i >= j) {
      break;
    }
    if (array[i] > max_1) {
      max_1 = array[i];
    }
    if (array[j] > max_2) {
      max_2 = array[j];
    }
  }
  return max_1 > max_2 ? max_1 : max_2;
}

int main() {
  int array [] = {1, 20, 3, 4, 5, 6, 7, 8, 19, 10};
  int max;
  if ((max = find_max (array, 10)) > 0) {
    std::cout << max << std::endl;
  }
  else {
    std::cout << "Array is empty" << std::endl;
  }
  return 0;
}
