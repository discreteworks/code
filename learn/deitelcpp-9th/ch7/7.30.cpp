#include <iostream>
#include <array>

using namespace std;

void printArray(array<int, 10> &array, int start, int end);

int main() {
  array<int, 10> array = {1,2,3,4,5,6,7,8,9,10};
  printArray(array, 0, 9);
  cout << endl;
  return 0;
}

void printArray(array<int, 10> &array, int start, int end) {
  if (start <= end) {
    cout << array [start] << " ";
    printArray(array, start + 1, end);
  }
}
