#include <iostream>
#include <cstring>
#include <unistd.h>

using namespace std;

void mystery2(const char *s, int n);

int main()
{
  char string1[ 80 ];

  cout << "Enter a string: ";

  cin >> string1;

  mystery2( string1, strlen(string1));

  return 0;
}

void mystery2(const char *s, int n)
{
  unsigned int x; // unsigned int is the problem as x will always be greater than 1 resulting in segmentation fault, make int x, than loop will terminate if x < 0.

  for ( x = n - 1; x >= 0; --x )
  {
    cout << s[x];
  }
}
