#include <iostream>

using namespace std;

int main()
{
  int number1;
  int number2;
  int max;
  int total = 1;

  /* LCM using the division method */

  cout << "Input number 1: ";

  cin >> number1;

  cout << "Input number 2: ";

  cin >> number2;

  max = number1 >= number2 ? number1 : number2;

  cout << "max: "<< max << endl;

  for ( int i = 2; (number1 > 1 || number2 > 1) && (i <= max);  )
  {
    if (0 == number1 % i && 0 == number2 % i )
    {
      number1 /= i;
      number2 /= i;
      total *=  i;
      cout << "if1 i: " << i << endl;
    }
    else if ( 0 == number1 % i)
    {
      number1 /= i;
      total *=  i;
      cout << "if2 i: " << i << endl;
    }
    else if ( 0 == number2 % i)
    {
      number2 /= i;
      total *=  i;
      cout << "if3 i: " << i << endl;
    }
    else
    {
      i++;
    }
  }
  cout << "LCM: " << total << endl;

  return 0;

}
