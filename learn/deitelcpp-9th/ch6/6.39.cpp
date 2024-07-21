#include <iostream>

using namespace  std;

void towerOfHanoi(int n);  // n is the number if disk  souce is pole 1, destination 3, temporary is pole 2

int main() {
  towerOfHanoi(4);
  return -1;
}

void towerOfHanoi(int n) {
  /* tower of hanoi is series based on a pattern similar to a pattern we have in fibnacci series
   * there are two parts in the series lets take an exampe from  recursive outcome.
   * 1 -> 3
   * 1 -> 2
   * 3 -> 2
   * 1 -> 3
   * 2 -> 1
   * 2 -> 3
   * 1 -> 3
   *
   * So there are two series. The first series can be deduced using formulae.
   * 1 1 3 1 2 2 1
   * where n =  {1..7}
   * n & (n-1) % 3 (bounded by 3 poles)
   * similarly the second series can deduced.
   * (n | (n -1) + 1) % 3 (bounded by 3 poles)
   *
   * These are mathematical models for patterns something similar to fibancci series 1 1 2 3 5
   * n + (n-1)
  */
  const int OFFSET = 1; //add offset to match 1, 2 and 3 poles

  for (int i = 1; i < (1 << n); i++) { // shift 1 by n gives 2^n
    int src = (i & (i-1)) % 3 + OFFSET;
    int dest = (((i | (i -1)) + 1) % 3) + OFFSET;
    cout << ((n % 2 == 0 && src > 1) ? (src == 2 ? 3 : 2) : src) << " -> " << ((n % 2 == 0 && dest > 1) ? (dest == 2 ? 3 : 2) : dest) << endl;
  }
}
