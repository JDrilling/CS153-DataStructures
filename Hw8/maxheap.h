/*Jacob Drilling.
 * maxHeap.h
 * Implementation of the abstract heap class
  */

#ifndef maxHeap_H
#define maxHeap_H

#include "abstractheap.h"
#include <string>

using namespace std;

template<typename T>
void prettyPrint (int  ix, int pad, int m_size, T* m_data);


template <typename T>
class maxHeap: public AbstractHeap<T>
{
public:


  friend void prettyPrint (int  ix, int pad);
  
  
   // Constructor  
   maxHeap(): m_size(0), m_max(0), m_data(NULL) {};
   
  /*** ----------- Big 3 ----------- ***/
  
  // Destructor
	~maxHeap() {clear();}
  
  
  
  // Operator ='s
  maxHeap<T>& operator=(const maxHeap<T>& rhs);
  
  // Copy Constructor
  maxHeap(const maxHeap<T>& cpy);

  /*** ---- Accessor Operations ---- ***/

  // Purpose: Checks if a Heap is empty
  // Returns: 'true' if the Heap is empty
  //     'false' otherwise  
  bool isEmpty() const {return m_size == 0;}
  
  // Purpose: Returns the size of the Heap.
  // Returns: the number of elements in the Heap
  int size() const {return m_size;}

  // Purpose: looks at the top of the heap
  // Returns: a reference to the element currently at the root of the Heap
  // Exception: if the Heap is currently empty, throw SOMETHING!!
  const T& top() const throw (string);  

  // Purpose: Prints the Heap In-Order with formatting
  //     each level indented 4 spaces, one element per line    
  void print() const {prettyPrint(1,0,m_size,m_data);}


  /*** ---- Mutator Operations ---- ***/
  
  // Purpose: clears the heap
  // Postconditions: the heap is now empty 
  void clear();
  
  // Purpose: insert an element into the heap
  // Parameters: x is the item to add to the heap
  // Postconditions: the heap now contains x, 
  void insert(const T& x);
  
  // Purpose: removes the root (top) of the heap 
  // Postconditions: the element formerly at the root of the heap 
  //     has been removed
  // removing from an empty Heap produces no errors, the Heap remains empty.
  void remove();
  
  
  
  
  private:
    int m_size;
    int m_max;
    T* m_data;
	
};




#include "maxHeap.hpp"

#endif 
