#include <iostream>

using namespace std;

int main() {
  int size;

  cout << "Enter Size:";
  cin >> size;
  for (int i  = 0 ; i < size ; i++) {
    for (int j = 0; j < size ; j++) {
      if (i == 0 || i == 4) {
        cout <<  "*";
      } else if (j == 0 || j == 4) {
        cout  << "*";
      } else {
        cout << " ";
      }
    }
    cout << endl;
  }
  return 0;
}
