#include <iostream>
#include <random>
#include <ctime>
#include <unistd.h>

using namespace std;

#define SLEEP_INTERVAL 1
void moveHare(char *squares, char **rabbitPtr, int roll);
void moveTortoise(char *squares, char **turtlePtr, int roll);

int main()
{
  char squares[70];
  char *turtlePtr = nullptr;
  char *rabbitPtr = nullptr;

  for (int i=0; i < 70; i++)
  {
    squares[i] = ' ';
  }

  default_random_engine  engine(static_cast<unsigned int > ( time (0)));
  uniform_int_distribution<unsigned int> randomInt(1,10);

  char *t  = squares;
  cout << std::hex << (long)t <<endl;
  cout << std::hex << (long)&squares[69] <<endl;
  //return 1 ;
  while(1)
  {
    moveTortoise(squares, &turtlePtr, randomInt(engine));
    moveHare(squares, &rabbitPtr, randomInt(engine));

    if (rabbitPtr > &squares[0] && rabbitPtr == turtlePtr)
      cout << "Ouch" << endl;
    *rabbitPtr = 'H';
    *turtlePtr = 'T';

    for (int j = 0; j < 70; j++)
      cout << squares[j];
    cout << endl;
    for (int j = 0; j < 70; j++)
      cout << '*';
    cout << endl;

    if (rabbitPtr == &squares[69])
    {
      cout << "Rabbit  Win." <<endl;
      break;
    }
    if (turtlePtr == &squares[69])
    {
      cout << "Turtle Win." <<endl;
      break;
    }
    sleep(SLEEP_INTERVAL);
  }
}

void moveHare(char *squares, char **rabbitPtr, int roll)
{

  if (*rabbitPtr == nullptr)
  {
    // init to first position 1.
    *rabbitPtr = squares;
    **rabbitPtr = 'H';
  }
  **rabbitPtr = ' ';
  switch (roll)
  {

  case 1 ... 2:
    break;
  case 3 ... 4:
    if (*rabbitPtr + 9 <= &squares[69])
    {
      *rabbitPtr += 9;
    }
    else
    {

      *rabbitPtr =  squares + 69;
    }
    break;

  case 5:
    if (*rabbitPtr - 12 >= &squares[0])
    {
      *rabbitPtr -= 12;
    }
    else
    {
      *rabbitPtr =  &squares[0];
    }
    break;
  case 6 ... 8:
    if (*rabbitPtr + 1 <= &squares[69])
    {
      *rabbitPtr += 1;
    }
    else
    {

      *rabbitPtr =  squares + 69;
    }
  case 10:
    if (*rabbitPtr - 2 >= &squares[0])
    {
      *rabbitPtr -= 2;
    }
    else
    {
      *rabbitPtr =  &squares[0];
    }
  default:
    break;
  }
}


void moveTortoise(char *squares, char **turtlePtr, int roll)
{

  if (*turtlePtr == nullptr)
  {
    // init to first position 1.
    *turtlePtr = squares;
    **turtlePtr = 'T';
  }
  **turtlePtr = ' ';
  switch (roll)
  {
  case 1 ... 5:
    if (*turtlePtr + 3 <= &squares[69])
    {
      *turtlePtr += 3;
    }
    else
    {

      *turtlePtr =  squares + 69;
    }
    //cout << std::hex<< (long)*rabbitPtr << endl;
    break;

  case 6 ... 7:
    if (*turtlePtr - 6 >= &squares[0])
    {
      *turtlePtr -= 6;
    }
    else
    {
      *turtlePtr =  &squares[0];
    }
    break;
  case 8 ... 10:
    if (*turtlePtr + 1 <= &squares[69])
    {
      *turtlePtr += 1;
    }
    else
    {

      *turtlePtr =  squares + 69;
    }
  default:
    break;
  }
}
