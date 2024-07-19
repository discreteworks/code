#include <iostream>

using namespace std;

int gcd(int x, int y);

int main ()
{
  cout << gcd(10,5) << endl;

  return 0;
}

int gcd(int x, int y)
{
  if ( y == 0 )
  {
    return x;
  }
  else
  {
    gcd (y, x % y);
  }
}
