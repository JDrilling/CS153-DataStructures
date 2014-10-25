#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
  srand(time(NULL));
  
  int randX = rand() % 100;
  int randY = rand() % 10;
  int randPower = 2*(rand() % 5) +1;

  if (randPower > randY)
    randPower = randY;
  else if (randPower > randX)
    randPower = randX;

  if (randPower % 2 == 0)
    randPower --;
  
  cout << 1 << endl;
  cout << randX << " " << randY << " " << randPower <<  endl;
  for (int i = 0; i < randY; i++)
  {
    for (int j = 0; j < randX; j++)
      cout << rand() % 200 << " ";

    cout << endl;
  }
  
  return 0;
}
