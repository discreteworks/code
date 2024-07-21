#include <iostream>

using namespace std;

int main() {
  /* The number of rows is also the number maximum stars in a row. */
  int n  = 5; // number of rows.
  int loop1, loop2;

  /* loop incremement by offset of 2 (1,3,5,7,9)
     as we have to print 5 rows we need to multiply
     the input row number with 2.
   */
  for (int i = 1; i <= n * 2; i += 2) {
    if (i > n) {
      loop1 = (i - n) / 2; // set the maximum no of space per row.
      loop2 =  n * 2 - i; // set maximum number of stars per row.
    } else {
      loop1 = (n - i) / 2; // set maximum no of spaces per row.
      loop2 = i; // set maximum no of stars per row.
    }
    for (int k = 1; k  <= loop1; k++) {
      cout  << " ";
    }
    for (int j = 1; j <= loop2 ; j++) {
      cout << "*";
    }
    cout << endl;
  }
  return 0;
}
