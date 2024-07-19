#include <iostream>
#include <cstdlib>

using namespace std;


int main ()
{
  int x;
  int y;

  x  = 2 + rand() % 11;
  while(1)
  {
    cout << "x: " << x << endl;
    if ( x % 2 == 0)
    {
      cout << "a: " <<  x << endl;
    }

    y = 3 + rand()  % 12;

    cout << "y:" << y << endl;

    if ( y % 3 == 0 )
    {
      cout << "b: " << y << endl;

      cout << "c: " << y * 2 << endl;
    }
  }

  return 0;
}
