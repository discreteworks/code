#include <iostream>

using namespace std;

void separator(int);

int main() {
  int val = 4562;

  separator(val);
  return 0;
}

void separator(int val) {
  int total = 0;
  int factor = 1;
  int temp = val;

  /* As we don't know how long is the integer, we need to calculate its factor.
   * The only mechanism to traverse an unknown integer is from reverse.
   * 4562 has a factor 1000, so if we pick 4 by division, we need to divide
   * 4562 by 1000 and similar for 562 is the remainder divide by 100 to get 5
   * till we reach 0.
   */
  while (1) {
    val /= 10;
    if (val <= 0)
      break;
    factor *= 10;
  }
  cout << "Factor:" << factor << endl;
  while (factor > 0) {
    cout << temp / factor << " ";
    temp %= factor;
    factor /= 10;
  }
  cout << endl;
}
