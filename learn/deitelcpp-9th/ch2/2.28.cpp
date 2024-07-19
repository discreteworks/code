#include <iostream>
using namespace std;
int main()
{
  int n;
  int factorial = 1;
  cin >> n;

  for( int i = 0 ; (n - i) >= 1; i++ )
  {
    factorial *=  ( n - i );

  }
  cout << factorial;
}
