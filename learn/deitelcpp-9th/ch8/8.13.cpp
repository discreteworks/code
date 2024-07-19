#include <iostream>

using namespace std;

void mystery(char *s1, const char *s2);

int main()
{
  char string1[80];
  char string2[80];

  int i;
  for (i = 0; i < 79; i++)
  {
    string1[i] = '1';
    string2[i] = '1';
  }
  string1[i]  = '\0';
  string2[i]  = '\0';

  cout << "Enter two strings: ";
  cin >> string1 >> string2;
  for (i = 0; i < 79; i++)
  {
    string1[i] = '1';
    string2[i] = '1';
  }
  string1[i]  = '\0';
  string2[i]  = '\0';

  mystery( string1, string2);
  cout  << string1 << endl;
}

void mystery(char *s1, const char *s2)
{
  while ( *s1 != '\0' )
  {
    ++s1;
  }
  for ( ; ( *s1 = *s2 ); ++s1, ++s2)
  {
    cout << "string:" << *s1  << endl;
    cout << "boolean:" << (( *s1 = *s2 )) << endl;
  }

}
