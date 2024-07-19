#include <iostream>
#include <array>
#include <cstring>

using namespace std;

bool testPalidrome (string &str, int start, int end);

int main ()
{
  string str = "able was a ere i saw elba";

  cout << str.length() << endl;

  cout << "Test : " << testPalidrome ( str, 0, str.length() - 1 ) << endl;

  return 0;

}

bool testPalidrome (string &str, int start, int end)
{
  if ( start < end )
  {
    if ( str [start] == str [end] )
    {
      // this return value will float to the top call if  test(a!=b) false - > test(a,a) false ->  test (b, b) false or true -> true
      bool flag = testPalidrome (str, start + 1, end - 1);
      cout << str [start] << " , " << str[end] << "flag:" << flag << endl;
      return flag;
    }
    else
    {
      cout << "Fail:" << str [start] << " , " << str[end] << endl;
      return false;
    }
  }
  cout << "Exit:" << str [start] << " , " << str[end] << endl;
  return true;

}
