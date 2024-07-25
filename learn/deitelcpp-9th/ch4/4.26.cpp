#include <iostream>

using namespace std;

int main() {
  int number;
  int total = 0;
  int temp;
  cout << "Enter number:";
  cin >> number;
  temp  = number;
  for (int x = 10000; x > 0; x /= 10) {
    total += (temp % 10) * x;
    temp  = temp / 10;
  }
  cout << total << endl;
  if (total == number) {
    cout << "Number is palindrome" << endl;
  } else {
    cout << "Not palindrome." << endl;
  }
  return 0;
}
