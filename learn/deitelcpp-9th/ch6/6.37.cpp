#include <iostream>

using namespace std;

int lcm(int, int, int);

int main() {
  int divisor = 1; // initializing it by 1 as 0 divisor is an error.
  int number1;
  int number2;

  cout << "Input number 1: ";
  cin >> number1;
  cout << "Input number 2: ";
  cin >> number2;
  cout << "LCM: " << endl << lcm(number1, number2, divisor) << endl;
  return 0;
}

int lcm(int num1, int num2, int divisor) {
  int total = 1;

  if (num1 == 1 && num2 == 1) {
    return 1;
  }
  cout << "divisor: " << divisor << " num1: " << num1 << " num2: " << num2 << endl;
  if (divisor == 1) {
    return total * lcm(num1, num2, divisor + 1);
  }
  if (0 == num1 % divisor) {
    total = divisor;
    num1 /= divisor;
  }
  if (0 == num2 % divisor) {
    total = divisor;
    num2 /= divisor;
  } else {
    divisor++;
  }
  return total * lcm(num1, num2, divisor);
}
