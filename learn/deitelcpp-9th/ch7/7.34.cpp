#include <iostream>
#include <array>
#include <ctime>
#include <random>

using namespace std;

const int SIZE = 12;
void printMaze(const array < array < char, ::SIZE >, ::SIZE > &a);
void mazeGenerator(array < array < char, ::SIZE >, ::SIZE > &a, int i, int j);

void printMaze(const array < array < char, ::SIZE >, ::SIZE > &a) {
  for ( int i = 0; i < ::SIZE; i++ ) {
    for ( int j = 0; j < ::SIZE; j++ ) {
      cout << a[i][j] << ' ';
    }
    cout << endl;
  }
  cout << endl;
}

void mazeGenerator(array < array < char, ::SIZE >, ::SIZE > &a, int i, int j) {
  default_random_engine gen{ static_cast< unsigned >( time( 0 ) ) };
  uniform_int_distribution< size_t > randomIntY( 1, 9);
  uniform_int_distribution< size_t > randomIntX( 1, 10);
  uniform_int_distribution< size_t > path( 0, 1);

  for (int x = 0; x < SIZE; x++) {
    for (int y = 0; y < SIZE; y++) {
      a[x][y] = 'X';
    }
  }
  a[i][j] = '.';
  a[i][j+1] = '.';
  int k = i;
  int h = j + 1;
  int x;
  int y;
  a[9][11] = '.';
  for (int u=0; u<12; u++) {
    int val1 = randomIntX( gen );
    int val2 = randomIntY( gen );

    if ( u == 0 ) {
      x = 9;
      y = 10;
    } else {
      if ( val1 % 2 == 0)
        x = val1;
      else
        x = val1 + 1;

      if ( val2 % 2 == 0) {
        y = val2;
      } else {
        y  = val2 + 1;
      }
    }
    while ( k != x || h != y ) {
      if (path(gen) == 1) {
        if (k == x) {
        } else if (k < x) {
          k++;
        } else {
          k--;
        }
      } else {
        if (h == y) {
        } else if (h < y) {
          h++;
        } else {
          h--;
        }
      }
      if (a[k+1][h] != '.' && a[k][h] != '.')
        a[k][h] = '.';
    }
    k = i;
    h = j + 1;
  }
}

int main() {
  array<array<char, ::SIZE>, ::SIZE > a;
  mazeGenerator(a, 2, 0);
  printMaze(a);
}
