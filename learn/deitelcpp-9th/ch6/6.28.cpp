#include <iostream>

using namespace std;

int isPerfect(int number);

int main() {
  for (int i = 1; i <= 1000; i++) {
    if (isPerfect(i)) {
      cout << i << " is perfect" << endl;
    }
  }
  return 0;
}

int isPerfect(int number) {
  int sum = 0;

  for (int i = 1; i < number; i++) {
    if ( 0 ==  number % i ) {
      sum += i;
    }
  }
  if (sum == number) {
    // print divisors of perfect no's.
    for (int i = 1; i < number; i++) {
      if ( 0 ==  number % i ) {
        cout << "number :" << number << " divisor:" << i << endl;
      }
    }
    return 1;
  } else {
    return 0;
  }
}
