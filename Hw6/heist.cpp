/* Jacob Drilling
 * Heist.cpp
 * Main function for benders heist
 */

#include <iostream>
#include "heistFunctions.h"
using namespace std;

int main()
{
  char mapSpace;
  int height, width;
  bool quit = false;
  int startX, startY, endX, endY;
  
  char** map;
  char space;
  
  while(!quit)
  {
    cin >> width >> height;
    
    if( height == 0 || width == 0)//quit condition.
      quit = true;
    else if (height > 0 && width > 0)//Make the map.
    {
      //Allocate map to have dimensions of height x width.
      map = new char*[width];

      for(int i = 0; i < width; i++)
        map[i] = new char[height];
      //end allocation.

      //------------Fill map----------//
      for(int i = height - 1; i >= 0; i--)
      {
        cin.ignore(256, '\n');
  
        for(int j = 0; j < width; j++)
        {
          cin.get(space);

          if(space == 'B')
          {
            startX = j;
            startY = i;
          }
          else if(space == 'E')
          {
            endX = j;
            endY = i;
          }

          map[j][i] = space;
        }
      }
      //------------Map Full-----------//

      if(findEnd(map, startX, startY, endX, endY))
      {
        cout << "Path Found!" << endl;
        //-----------Output Map------------//
        for(int i = height - 1;i >= 0; i--)
        {
          for (int j = 0; j < width; j++)
            cout << map[j][i];
          
          cout << endl;
        }
        //-------------End output------------//
      }
      else
        cout << "No path found!"  << endl;
    
      

      //DeAllocate map.
      for(int i = 0; i < width; i++)
        delete [] map[i];
    
      delete [] map;
      //end Deallocation.
    }
    else // Invalid map size.
      cout << "Please enter a valid map size" << endl;
  }
  return 0;
}
