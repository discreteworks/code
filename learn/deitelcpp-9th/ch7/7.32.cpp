#include <iostream>
#include <array>

using namespace std;

int recursiveMinimum ( array<int, 10> &arr, int start, int end );

int main ()
{
  array < int, 10 > arr =  { 26, 14, 15, 23, 32, 10, 13, 11, 10, 8 };

  cout << recursiveMinimum ( arr, 0, 9 ) << endl;

  return 0;
}

int recursiveMinimum ( array<int, 10>  &arr, int start, int end )
{
  if ( start < end )
  {
    int next =  recursiveMinimum ( arr, start + 1, end );
    if ( arr[start] <= next )
      return arr[start];
    else
      return next;
  }
  // reach the end of array now return the value of last element.
  // this value will be than equal to next and compared with previous functional call.
  return arr[start];
}
