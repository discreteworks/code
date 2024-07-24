#include <iostream>

using namespace std;

int main() {
  int n;
  int factorial = 1;

  cout << "Input number:";
  cin >> n;
  if (n < 0) {
    cout << "Please input non-negative number" << endl;
    return 0;
  }
  for (int i = 0; (n - i) >= 1; i++) {
    factorial *= ( n - i );
  }
  cout << factorial << endl;
  return 0;
}
