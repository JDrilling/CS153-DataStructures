#ifndef MYBSTREE_H
#define MYBSTREE_H

#include "AbstractBSTree.h"
#include "treenode.h"

template < typename T>
class MyBSTree: public AbstractBSTree<T>
{
  public:
  
  MyBSTree(): m_size(0){m_root = new TreeNode<T>(NULL, NULL);}
       /* ------------ Big 3 ------------ */
//Destructor
  ~MyBSTree(){clear(); delete m_root;}
  
//Operator ='s
  MyBSTree& operator =(const MyBSTree& rhs);
  
//Copy Constructor
  MyBSTree(const MyBSTree& copy):m_root(NULL),m_size(0){*this = copy;}
      
       /* ----- Accessor Operations ----- */
  
// Purpose: Accessor function for the number of elements in the tree
// Returns: number of elements in the tree 
  virtual int size() const {return m_size;}


// Purpose: Checks if a tree is empty
// Returns: 'true' if the tree is empty
//     'false' otherwise  
  virtual bool isEmpty() const {return m_size == 0;}


// Purpose: Returns the height of the tree
// Returns: height the tree 
  virtual int height() const{if(m_size > 0) return nodeHeight(m_root); 
                              else return 0;}


// Purpose: finds the maximum element in the Tree
// Returns: a const reference to the maximum element
  virtual const T& findMax() const throw (string);


// Purpose: finds the minimum element in the Tree
// Returns: a const reference to the minimum element
  virtual const T& findMin() const throw (string);


// Purpose: finds an element in the Tree
// Parameters: x is value to be found 
// Returns: 
//     If The tree contains x then  
//         return N, the level of the node containing x
//         (the root is considered level 0)
//     If The tree does not contains x then  
//         return -N, where N is the level of the tree reached in the search 
  virtual int contains(const T& x) const;


    
  /*** ---- Mutator Operations ---- */

  
// Purpose: Clears the Tree
// Postconditions: an empty Tree
  virtual void clear();


// Purpose: Inserts an element into a tree
// Parameters: x is value to be added to the tree
// Postconditions: The tree now contains x
//     if the tree already contains x, ignore insertion
  virtual void insert(const T& x);

    
// Purpose: Removes an element from the tree
// Parameters: x, the element to remove
// Postconditions: the tree does not contains x
  virtual void remove(const T& x);
          
     
  /*** ---- Output Operations ---- */

// Purpose: Prints the Tree in Pre-Order    
  virtual void printPreOrder() const {if(m_size > 0)printPre(m_root);}


// Purpose: Prints the Tree in Pre-Order    
  virtual void printPostOrder() const {if(m_size > 0)printPost(m_root);}


// Purpose: Prints the Tree In-Order with formatting
//     each level indented 4 spaces, one element per line    
  virtual void print() const {if(m_size > 0)prettyPrint (m_root);}
  
  
  private:
    TreeNode<T>* m_root;
    int m_size;
};

#include "MyBSTree.hpp"

#endif 
