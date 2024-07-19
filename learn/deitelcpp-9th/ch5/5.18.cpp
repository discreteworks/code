#include <iostream>
#include <iomanip>

using namespace std;

int toBin ( int number );
int toOct ( int number );
void toHex(int number, char *hex);
inline char convertHexNotation(int number);

int main()
{
  int i  = 1;
  char hex[3];
  cout <<  "Show decimal equivalent 1-256" << endl;
  cout << "Decimal" << "|" << "Binary" << "|" << "Octal" << "|" <<  "Hexadecimal" << endl;

  while ( i <= 256 )
  {
    toHex(i, hex);
    cout << i << setw(15) << toBin(i) << setw(15) << toOct(i) << setw(15) <<'|' << hex << endl;
    i++;

  }

  return 0;

}

int toBin(int number)
{
  int  mul = 1;
  int output = 0;
  while (number > 0)
  {
    output += number % 2 * mul;
    number /= 2;
    mul = mul * 10;
  }
  return output;
}

int toOct(int number)
{
  int  mul = 1;
  int output = 0;
  while (number > 0)
  {
    output += number % 8 * mul;
    number /= 8;
    mul = mul * 10;
  }
  return output;
}


void toHex(int number, char *hex)
{
  int  i = 0;
  int temp = number;
  int count = 0;
  int flag = 0;

  while ( number > 0 )
  {
    // add to the top of stack
    hex[0] = convertHexNotation(number % 16);

    if(number /= 16)
    {
      i  = count;
      // slide the stack for new items
      // a new number exists.
      // existing  stack |B|C|
      // stack size 2 count = 1
      // iterative slide from tail by 1.
      while(i >= 0)
      {
        hex[i+1] = hex[i];
        i--;
      }
    }
    count++;

  }
  // terminate the string
  hex[count] = '\0';



}

inline char convertHexNotation(int number)
{
  int notation;

  switch(number)
  {
  case 10:
    notation = 'A';
    break;
  case 11:
    notation = 'B';
    break;
  case 12:
    notation = 'C';
    break;
  case 13:
    notation = 'D';
    break;
  case 14:
    notation = 'E';
    break;
  case 15:
    notation = 'F';
    break;
  default:
    notation = 48 + number;
    break;
  }
  return notation;

}
