#include <iostream>
#include <array>

using namespace std;

int main ()
{
  const int size = 1000;

  array < int, size> prime = {0};

  for ( int i = 1; i < size; i++ )
  {
    prime[i] = 1;
  }

  for ( int i = 2; i < size ; i++ )
  {
    for ( int j = i + i; j < size; j += i )
    {
      prime[j] = 0;
    }
  }

  for ( int i = 2; i < size; i++ )
  {
    //cout << prime[i];
    if ( prime[i] != 0 )
    {
      cout << i << ", ";
    }
  }

  cout << endl;

  return 0;
}
