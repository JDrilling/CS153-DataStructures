/* Jacob Drilling
 * Section A
 * bday.cpp
 * contains main for hw9 of cs153fs2013
 */
 
 #include <iostream>
 #include "graph.h"
 using namespace std;
 
int main()
{
  Graph* city;
  string cityName, locName, sTo, sFrom;
  int numTrials, numLocs, 
      numTokens, weight, 
      numNeighbors;
 
      
  cin >> numTrials;
  
  /*------------- Main loop ------------------*/
  //Each rotation = new city/trial
  for(int i = 0; i < numTrials; i++)
  {
  /*--------------Pre-Trial input-------------*/
    cin >> numTokens;
    cin >> cityName >> numLocs;
    
    city = new Graph(numLocs);
  /*-----------Loop to get neighbors----------*/
    for(int j = 0; j < numLocs; j++)
    {
      cin >> sFrom >> numNeighbors;
      for(int k = 0; k < numNeighbors; k++)
      {
        cin >> sTo >> weight;
        city->insert(sTo, sFrom, weight);
      }
    }
  /*-----------Perform Tests on matrix---------*/
  /*-----------Final Output for City------------*/
    //Optional print of the adjacency Matrix.
    //city->printMatrix();
    cout << "In " << cityName << ", Bender can reach:" << endl;
    city->findPaths(numTokens);
    
    delete city;
  }
  return 0;
}