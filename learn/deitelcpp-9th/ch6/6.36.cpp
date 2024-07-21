#include <iostream>

using namespace std;

int exponential(int number, int n);

int main() {
  int number;
  int exponent;

  cout << "Enter number: ";
  cin >> number;
  cout << "Enter exponent: ";
  cin >> exponent;
  cout <<  "Exponential: " << exponential(number, exponent) << endl;
  return 0;
}

int exponential(int number, int n) {
  // base case as number ^ 0 = 1
  if (0 == n) {
    return 1;
  }
  return number * exponential(number, n - 1);
}
