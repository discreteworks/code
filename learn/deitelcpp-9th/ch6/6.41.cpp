#include <iostream>

using namespace std;

int gcd(int x, int y);

int main() {
  int input1;
  int input2;

  cout << "Input number 1:";
  cin >> input1;
  cout << "Input number 2:";
  cin >> input2;
  cout << "GCD:" << gcd(input1, input2) << endl;
  return 0;
}

int gcd(int x, int y) {
  if (y == 0) {
    return x;
  } else {
    return gcd(y, x % y);
  }
}
