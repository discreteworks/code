#include <iostream>

using namespace  std;

void towerOfHanoi(int n, int source, int dest, int temp);  // n is the number if disk  souce is pole 1, destination 3, temporary is pole 2

int main() {
  towerOfHanoi(4,1,3,2);
  return -1;
}

void towerOfHanoi(int n, int source, int dest, int temp) {
  if (n == 1) {
    cout << source << " ->> " <<  dest << endl;
    return;
  }
  towerOfHanoi(n - 1, source, temp, dest);  // move from pole 1 to pole 2
  cout << source << " -.> " <<  dest << endl;
  towerOfHanoi(n - 1, temp, dest, source);  // move from pole 2 to pole 3
}
