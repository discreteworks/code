#include <iostream>
#include <array>
#include <unistd.h>
const int SIZE = 12;
enum DIRECTION {TOP = 0, BOTTOM, RIGHT, LEFT};

using namespace std;

void mazeTraversal(array < array < char, ::SIZE >, ::SIZE > &a, int i, int j);
void printMaze(const array < array < char, ::SIZE >, ::SIZE > &a);
string  printEnum(DIRECTION d);

void printMaze(const array < array < char, ::SIZE >, ::SIZE > &a) {
  for (int i = 0; i < ::SIZE; i++) {
    for (int j = 0; j < ::SIZE; j++) {
      cout << a[i][j] << ' ';
    }
    cout << endl;
  }
  cout << endl;
}

string  printEnum(DIRECTION d) {
  switch (d) {
  case 0:
    return "TOP";
  case 1:
    return "BOTTOM";
  case 2:
    return "RIGHT";
  case 3:
    return "LEFT";
  default:
    return NULL;
  }
}

int main() {
  array<array<char, ::SIZE>, ::SIZE > array  = {
    '#','#','#','#','#','#','#','#','#','#','#','#',
    '#','.','.','.','#','.','.','.','.','.','.','#',
    '.','.','#','.','#','.','#','#','#','#','.','#',
    '#','#','#','.','#','.','.','.','.','#','.','.',
    '#','.','.','.','.','#','#','#','.','#','.','#',
    '#','#','#','#','.','#','.','#','.','#','.','#',
    '#','.','.','#','.','#','.','#','.','#','.','#',
    '#','#','.','#','.','#','.','#','.','#','.','#',
    '#','.','.','.','.','.','.','.','.','#','.','#',
    '#','#','#','#','#','#','.','#','#','#','.','#',
    '#','.','.','.','.','.','.','.','.','.','.','#',
    '#','#','#','#','#','#','#','#','#','#','#','#',
  };

  mazeTraversal (array, 2, 0);

  return 0;
}

void mazeTraversal (array < array < char, ::SIZE >, ::SIZE > &a, int i, int j) {
  static ::DIRECTION direction = RIGHT;
  static int terminate = -1;

  if ((i == ::SIZE - 1 || j == ::SIZE - 1) && a[i][j] == '.') {
    cout << "direction:"<< printEnum(direction) << endl;
    cout << "i:"<< i << " j:" << j << endl;
    a[i][j] = 'X' ;
    printMaze(a);
    terminate = 1;
  }
  if (terminate != 1) {
    cout << "direction:"<< printEnum(direction) << endl;
    cout << "i:"<< i << " j:" << j << endl;
    a[i][j] = 'X' ;
    printMaze(a);
    a[i][j] = '.' ;
    usleep(100000);
    if (direction == RIGHT) {
      if (a[i + 1][j + 1] == '#') {
        if (a[i][j + 1] == '.') {
          j = j + 1;
        } else if (a[i][j + 1] == '#') {
          direction = TOP;
        }
      } else if (a[i + 1][j + 1] == '.') {
        j = j + 1;
        direction = BOTTOM;
      }
      mazeTraversal(a, i, j);
    }
    if (direction == TOP) {
      if (a[i - 1][j + 1] == '#') {
        if (a[i - 1][j] == '.') {
          i = i - 1;
        } else if (a[i - 1][j] == '#') {
          direction = LEFT;
        }
      } else if (a[i - 1][j] == '.') {
        i = i - 1;
        direction = RIGHT;
      }
      mazeTraversal(a, i, j);
    }
    if (direction == BOTTOM) {
      if (a[i + 1][j -1] == '#') {
        if (a[i + 1][j] == '.') {
          i = i + 1;
        } else if (a[i + 1][j] == '#') {
          direction = RIGHT;
        }
      } else if (a[i + 1][j - 1] == '.') {
        i = i + 1;
        direction = LEFT;
      }
      mazeTraversal(a, i, j);
    }
    if (direction == LEFT) {
      if (a[i - 1][j -1] == '#') {
        if (a[i][j -1] == '.') {
          j = j - 1;
        } else if (a[i][j -1] == '#') {
          if (a[i + 1][j] == '.') {
            direction = BOTTOM;
          } else {
            direction = RIGHT;
          }
        }
      } else if (a[i -1][j - 1] == '.') {
        j = j - 1;
        direction = TOP;
      }
      mazeTraversal(a, i, j);
    }
  }
  return;
}
