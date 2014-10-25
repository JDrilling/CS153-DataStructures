/*Jacob Drilling
 *fishbomb.cpp
 *cs153 hw1
 */

#include <iostream>
using namespace std;

int main()
{
  int width, height, power, numBoards;
  int maxFish, tempFish, maxX, maxY;
  int **grid;

  //--------Get the number of boards and start main loop--------
  cin >> numBoards;
  for(int boardNum = 0; boardNum < numBoards; boardNum++)
  {
    maxFish = 0; //Max num of fish that can be caught. 0 for init comparison.
    cin >> width >> height >> power;
    
    //-------------------------create the grid/board------------
    grid = new int* [width];
    for (int j = 0; j < width; j++)
      grid[j] = new int[height];

    //-----------------------Fill the grid-----------------------
    for (int j = 0; j < height; j++)
      for (int k = 0; k < width; k++)
        cin >> grid[k][j];

    //-----------------Calculate where the max is----------------
    
    for (int yCoord = (power-1)/2; yCoord < height - (power-1)/2; yCoord++)
      for (int xCoord = (power-1)/2; xCoord < width - (power-1)/2; xCoord++)
      {
        tempFish = 0;
        for (int j = yCoord - (power-1)/2; j <= yCoord + (power-1)/2; j++)
          for (int k = xCoord - (power-1)/2; k <= xCoord + (power-1)/2; k++)
            tempFish += grid [k][j];

        if(tempFish > maxFish)
        {
          maxFish = tempFish;
          maxX = xCoord;
          maxY = yCoord;
        }
      }
  
    cout << "#" << boardNum << ": (" << maxX << ", " << maxY << ") " << maxFish << endl;
    
    //---------------------delete the grid---------------------
    for (int j = 0; j < width; j++)
      delete [] grid[j];

    delete [] grid;

  }

  return 0;
}
