#include <iostream>

using namespace std;

int main() {
  int size;

  cout << "Enter Size:";
  cin >> size;
  if (size <= 0 ||size > 20) {
    cout << "Please enter between [1-20]" << endl;
    return 0;
  }
  for (int i  = 0 ; i < size ; i++) {
    for (int j = 0; j < size ; j++) {
      if (i == 0 || i == (size -1)) {
        cout <<  "*";
      } else if (j == 0 || j == (size -1)) {
        cout  << "*";
      } else {
        cout << " ";
      }
    }
    cout << endl;
  }
  return 0;
}
