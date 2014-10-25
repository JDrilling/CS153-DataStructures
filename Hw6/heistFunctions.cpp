/*Jacob Drilling
 *heistFunctions.cpp
 *implementations of hestiFunctions.h
 */

#include "heistFunctions.h"
#include <iostream>
using namespace std;

bool findEnd(char** map, const int &startX, const int &startY, 
             const int &endX, const int & endY)
{
  enum direction {North, East, South, West};

  int moveDir;
  int numChoices = 4;
  int newX, newY;
  bool solved;

  do{
    if(numChoices == 4)
    {
      if(endX >= startX && endY > startY)
        moveDir = North;
      else if(endX > startX && endY <= startY)
        moveDir = East;
      else if(endX <= startX && endY < startY)
        moveDir = South;
      else if(endX < startX && endY >= startY)
        moveDir = West;
    }
    else
    {
      if(moveDir == West) //Have to move direction back to the begining of list
        moveDir = North;
      else
        moveDir ++;
    }
    
    numChoices --;

    switch(moveDir)
    {
      case North:
        newY = startY + 1;
        newX = startX;
        break;
      case East:
        newX = startX + 1;
        newY = startY;
        break;
      case South:
        newY = startY - 1;
        newX = startX;
        break;
      case West:
        newX = startX - 1;
        newY = startY;
        break;
    }

    if(map[newX][newY] == ' ' || map[newX][newY] == 'E') //if choice is valid.
    { 
		
      //cout << "Moving to (" << newX << ", " << newY << ")." << endl;
      if(map[newX][newY] == 'E') // If we're at the end return true;
        return true;
      else //else try the next step.
      {
        map[newX][newY] = '.'; 
        solved = findEnd(map, newX, newY, endX, endY);
        if(solved) //If the next choice was able to solve the map return true;
          return true;
        else //If the next choice was not able to solve undo choice.
        {
          map[newX][newY] = ' ';
          
          //cout << "Dead end reached. Undoing move to (" << newX << ", " << newY << ")." << endl;
        }
      }
    }
  }while(numChoices > 0); //Out of choices, return false.
  return false;
}

