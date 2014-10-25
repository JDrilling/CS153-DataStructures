/* Jacob Drilling
 * Section A
 * adjacency matrix - graph
 */
 
#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <iostream>
using namespace std;

class Graph
{
  public:
  
  /* ---------- Constructor --------- */
    Graph(const int max);
  /* ---------- Destructor ---------- */
    ~Graph();
    
  /* ------ Other Functionality ----- */
  
    /* Dec: Inserts a new location into the graph.
     * Pre: None.
     * Post: If the location is new, it is created locNames
     *       and the new weight is added to the graph
     *       Calls addLoc;
     */
    void insert(const string sTo, const string sFrom, const int weight);
    
    /* Dec:: Inserts a location into the locNames list
     * Pre: Should have enough room in locNames to add names
     * Post: Names are added to locNames IF NOT ALREADY THERE.
     *        Exists without adding names if they exists.
     */
    void addLoc(const string newLoc);
    
    /* Dec: Finds path of a certain total weight
     * Pre: None.
     * Post: Prints to the console destinations that can be
     *       reached from the airport witha total weight.
     */
    void findPaths(const int totWeight);
    
    
    //Outputs the Matrix to the console.
    void printMatrix();
  
  private:
    int** graph;
    int numLocs, maxLocs;
    string* locNames;
    
};

//Recursive function used in find reachable.
void recursiveReachable(int curNode, int curWeight, const int maxWeight, bool* &reachable, int** graph, const int maxLocs);
 
 
 #endif