#include <iostream>
#include <array>
#include <ctime>
#include <random>

using namespace std;

const int SIZE = 12;
void printMaze(const array < array < char, ::SIZE >, ::SIZE > &a);
void mazeGenerator(array < array < char, ::SIZE >, ::SIZE > &a, int i, int j);

void printMaze(const array < array < char, ::SIZE >, ::SIZE > &a)
{
  for ( int i = 0; i < ::SIZE; i++ )
  {
    for ( int j = 0; j < ::SIZE; j++ )
    {
      cout << a[i][j] << ' ';
    }
    cout << endl;
  }
  cout << endl;
}


void mazeGenerator(array < array < char, ::SIZE >, ::SIZE > &a, int i, int j)
{
  default_random_engine gen{ static_cast< unsigned >( time( 0 ) ) };
  uniform_int_distribution< size_t > randomIntY( 1, 9);
  uniform_int_distribution< size_t > randomIntX( 1, 10);
  uniform_int_distribution< size_t > path( 0, 1);

  for (int x = 0; x < SIZE; x++)
  {
    for (int y = 0; y < SIZE; y++)
    {
      a[x][y] = 'X';
      // if (x > 0 && y > 0 && (x%2==0) && (y%2==0))
      //   a[x][y] = '.';
    }
  }
//     for (int x = 1; x < SIZE; x+=2)
//     {
//         for (int y = 1; y < SIZE; y+=2)
//         {
//             if ( path(gen)  && x - 1 && y != ::SIZE - 1 )
//             {
//                 a[ x - 1 ][ y ] = '-';
//             }
//             if ( y - 1 && x != ::SIZE - 1 )
//                 a[ x ][ y - 1 ] = '+';
//             else if ( x - 1 && y != ::SIZE - 1 )
//                 a[ x - 1 ][ y ] = '.';
//
//             if ( x != ::SIZE - 1 && y != ::SIZE - 1 )
//                 a[ x ][ y ] = '.';
//
//         }
//     }


  a[i][j] = '.';
  a[i][j+1] = '.';
  int k = i;
  int h = j + 1;
  int x;
  int y;
  a[9][11] = '.';
  for (int u=0; u<12; u++)
  {
    int val1 = randomIntX( gen );
    int val2 = randomIntY( gen );

    if ( u == 0 )
    {
      x = 9;
      y = 10;
    }
    else
    {
      if ( val1 % 2 == 0)
        x = val1;
      else
        x = val1 + 1;

      if ( val2 % 2 == 0)
      {
        y = val2;
      }
      else
      {
        y  = val2 + 1;
      }
    }
    //cout << x << endl;
    // cout << y << endl;

    while ( k != x || h != y )
    {
      // cout << "OK";
      if (path(gen) == 1)
      {
        if (k == x)
        {
          //cout << "OK1"<<endl;
        }
        else if (k < x)
        {
          k++;
        }
        else
        {
          k--;
        }
      }
      else
      {
        if (h == y)
        {
          //cout << "OK2"<<endl;
        }
        else if (h < y)
        {
          h++;
        }
        else
        {
          h--;
        }
      }
      if (a[k+1][h] != '.' && a[k][h] != '.')
        a[k][h] = '.';
    }
    k = i;
    h = j + 1;
    // cout << k << endl;
    //  cout << h << endl;

    // printMaze(a);
  }

}

int main ()
{

  array<array<char, ::SIZE>, ::SIZE > a;
  mazeGenerator(a, 2, 0);
  //while (1)
  printMaze(a);


}
