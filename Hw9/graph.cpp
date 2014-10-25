/* Jacob Drilling
 * Section A
 * adjacency matrix - graph
 * Implementations of Graph DS
 */
 
#include "graph.h"
 
Graph::Graph(int max)
{
  maxLocs = max;
  graph = new int*[maxLocs];
  
  for(int i = 0; i < maxLocs; i++)
  {
    graph[i] = new int[maxLocs];
    //Initialize to all 0's
    for(int j = 0; j < maxLocs; j++)
      graph[i][j] = 0;
  }
    
  locNames = new string[maxLocs];
  
  locNames[0] = "airport"; //First Location is always the airport.
  numLocs = 1;
}
 
Graph::~Graph()
{
  for(int i = 0; i < maxLocs; i ++)
    delete [] graph[i];
  
  delete [] graph;
  
  delete [] locNames;
  
  graph = NULL;
  locNames = NULL;
}
 
 
void Graph::insert(const string sTo, const string sFrom, const int weight)
{
  int iTo = -1;
  int iFrom= -1; //Stores the integer values of their locaion in the matrix.
  int counter = 0;
  /* Check to see if the new locs need to be added */
  addLoc(sTo);
  addLoc(sFrom);
  
  
  /* first find the correct row to add it in. */
  while((iTo < 0 || iFrom < 0) &&  counter < numLocs)
  {
    if(sTo == locNames[counter])
      iTo = counter;
    if(sFrom == locNames[counter])
      iFrom = counter;
      
    counter ++;
  }
  /* add the new weights */
  if(iTo >= 0 && iFrom >= 0)//Only adds it if the locations passed all checks.
    graph[iFrom][iTo] = weight;
  
  
  return;
}
 

void Graph::addLoc(const string newLoc)
{
  if(numLocs < maxLocs)
  {
  
    for(int i = 0; i < numLocs; i ++)
      if(locNames[i] == newLoc)
        return; //Name exists so just exit.
    
    locNames[numLocs] = newLoc;
    numLocs++;
    
  }
  return;
}

void Graph::printMatrix()
{
  for(int i = 0; i < maxLocs; i++)
  {
    for(int j = 0; j < maxLocs; j++)
      cout << graph[i][j] << ' ';
      
    cout << endl;
  }
  return;
}
 
 
void Graph::findPaths(const int totWeight)
{
  bool noLocs = true;
  bool* reachable = new bool[maxLocs];

for( int i = 0; i < numLocs; i++)
    reachable[i] = false;

  recursiveReachable(0,0,totWeight,reachable,graph,maxLocs);
  
  for(int i = 0; i < maxLocs; i++)
    if(reachable[i])
    {
      noLocs = false;
      cout << locNames[i] << endl;
    }
  
  if(noLocs)
    cout << "Nothing. D:" << endl;
    
  delete [] reachable;
}


void recursiveReachable(int curNode, int curWeight, const int maxWeight, bool* &reachable, int** graph, const int maxLocs)
{
  for(int i = 0; i < maxLocs; i++)
    if(curWeight + graph[curNode][i] <= maxWeight && graph[curNode][i] > 0)
    {
      reachable[i] = true;
      recursiveReachable(i,curWeight + graph[curNode][i],maxWeight, reachable, graph, maxLocs);
    }
}