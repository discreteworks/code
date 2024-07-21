#include <iostream>

using namespace std;

int main() {
  // within  for loop ++i  is equivalent to i++
  // as its a statement
  for (unsigned int i = 2; i <= 6; ++i) {
    for (unsigned int j = 2; j <= 8; ++j) {
      for (unsigned int k = 2; k <= 7; ++k) {
        cout << "*";
      }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}
