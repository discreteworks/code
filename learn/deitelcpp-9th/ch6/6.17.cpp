#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
  int number;
  int found = 0;
  int start_value = 2;
  int set_a[] = {2, 4, 6, 8, 10};
  int set_b[] = {3, 5, 7, 9, 11};
  int set_c[] = {6, 10, 14, 18, 22};

  while (found == 0) {
    srand(time(NULL));
    number  = start_value + rand() % 22;
    for (int i = 0; i < sizeof(set_a) / sizeof(int); i++) {
      if (number == set_a[i]) {
        cout << "A random number " << number << " from set a" << endl;
        found = 1;
      }
    }
    for (int i = 0; i < sizeof(set_b) / sizeof(int); i++) {
      if (number== set_b[i]) {
        cout << "A random number " << number << " from set b" << endl;
        found = 1;
      }
    }
    for (int i = 0; i < sizeof(set_c) / sizeof(int); i++) {
      if (number == set_c[i]) {
        cout << "A random number " << number << " from set c" << endl;
        found = 1;
      }
    }
  }
  return 0;
}
