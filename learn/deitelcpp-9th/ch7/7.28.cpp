#include <iostream>
#include <array>
#include <cstring>

using namespace std;

bool testPalindrome(string &str, int start, int end);

int main() {
  string str[] = {"able was a ere i saw elba", "able was a ere a saw elba"};
  cout << "Test : " << testPalindrome ( str[0], 0, str[0].length() - 1 ) << endl;
  cout << "Test : " << testPalindrome ( str[1], 0, str[1].length() - 1 ) << endl;
  return 0;
}

bool testPalindrome(string &str, int start, int end) {
  if ( start < end ) {
    if (str [start] == str [end]) {
      // this return value will float to the top call if  test(a!=b) false - > test(a,a) false ->  test (b, b) false or true -> true
      bool flag = testPalindrome(str, start + 1, end - 1);
     return flag;
    } else {
      cout << "Fail:" << str [start] << " , " << str[end] << endl;
      return false;
    }
  }
  return true;
}
