#include <iostream>
#include <string>

using namespace std;

void stringReverse(string &str, int start);

int main() {
  string str =  "abcdefgh";
  stringReverse(str, 0);
  return 0;
}

void stringReverse(string &str, int start) {
  if ( str[start] !=  '\0' ) {
    stringReverse(str, start + 1);
    cout << str [start];
  }
}
