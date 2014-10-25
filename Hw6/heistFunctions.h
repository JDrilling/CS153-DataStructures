/* Jacob Drilling
 * heistFunctions.h
 * Header file for the functions to heist.cpp
 */


/* This is a recursive algorithm to find the path out of a heist. 
 * Pre: startX and startY must be valid coordinates in the map and 
 *      greater than 0.
 * post: Returns true if a path is found and map is modified to show that
 *       path.
 */


#ifndef HEISTFUNCTIONS_H
#define HEISTFUNCTIONS_H


//Finds the path from start to end on the character map.
//pre: Start point and end point must be valid map conditions.
//Post: map is changed to show the path if one is available.
//      if no path is possible, then the map is unchanged.
bool findEnd(char** map, const int &startX, const int &startY, const int &endX, const int &endY);


#endif
