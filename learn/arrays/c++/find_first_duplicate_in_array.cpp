#include <iostream>
#define NUM_RANGE 100

int find_first_duplication_in_array (int array[], int len) {
  int map[NUM_RANGE] = {0};
  for (int i = 0; i < len; i++) {
    if (map[array[i]] ==  1) return array[i];
    map[array[i]] = 1;
  }
  return -1;
}

int main() {
  int array[] = {1, 2, 3, 4, 5, 6, 2};
  std::cout << "first duplicate number:" << find_first_duplication_in_array(array, sizeof(array) / sizeof(int)) << std::endl;
}

