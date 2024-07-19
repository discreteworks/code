#include <iostream>

using namespace std;

int main()
{
  int number;

  cin >> number;

  int temp  = number;
  int total = 0;


  for ( int x = 10000 ; x > 0 ; x /= 10 )
  {
    total += (temp % 10) * x;
    temp  = temp / 10;

  }

  if ( total == number)
  {
    cout << "Number is palendrome";

  }
  else
  {
    cout << " Not palendrome.";
  }

  return 0;
}
