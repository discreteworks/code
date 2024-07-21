#include <iostream>

using namespace std;

int main() {
  int number;
  int total = 0;
  int temp;

  cin >> number;
  temp  = number;
  for (int x = 10000; x > 0; x /= 10) {
    total += (temp % 10) * x;
    temp  = temp / 10;
  }
  if (total == number) {
    cout << "Number is palendrome";
  } else {
    cout << " Not palendrome.";
  }
  return 0;
}
