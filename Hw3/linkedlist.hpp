//Jacob Drilling
//linkedlist.hpp
//implementation of a linked list.

template <class T>
const LinkedList<T>& LinkedList<T>::operator= (const LinkedList<T>& rhs)
{
  LinkedList* tmpLhs;
  LinkedList* tmpRhs = rhs.m_next;
  
  if(this != &rhs)
  {
    //Clear lhs cause it doesn't matter anymore
    this->clear();

    //iff rhs is empty, clear made lhs empty so stop here.
    if (rhs.m_next != NULL)
    {
      //Put rhs data in the first cell.
      this->m_data = rhs.m_data;

      //Creates the second item in the list.(or the sentinel)
      tmpLhs = new LinkedList;
      
      //make this point to the second item in the new list.
      //this list is elemets 1-sentinel.
      this->m_next = tmpLhs;

      //Recreate lhs to be the same as rhs.
      while(tmpRhs->m_next != NULL)
      {
        //set the data of the first element.
        tmpLhs->m_data = tmpRhs->m_data;
          
        //advance in rhs
        tmpRhs = tmpRhs->m_next;
        //add an element to lhs
        tmpLhs->m_next = new LinkedList;
        //advance in lhs.
        tmpLhs = tmpLhs->m_next;
      }
      
      tmpLhs->m_next = NULL;
    }
 }
  return *this;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& rhs)
{
  m_next = NULL;
  *this = rhs;
}

template <class T>
int LinkedList<T>::size() const
{
  int size = 0;
  LinkedList* tmp = m_next;
  
  //While you're not in the sentinel pointer increment size.
  while(tmp != NULL)
  {
    size++;
    tmp = tmp->m_next;
  }

  return size;
}

template <class T>
bool LinkedList<T>::isEmpty() const
{
  if(m_next == NULL)
    return true;
  else
    return false;
}

template <class T>
LinkedList<T>* LinkedList<T>::getFirstPtr()
{
  if(m_next != NULL)
    return this;
  else
  {
    std::cout << "PANIC in LinkedList.getFirstPtr() - empty list" << std::endl;
    return NULL;
  }
}

template <class T>
LinkedList<T>* LinkedList<T>::getLastPtr()
{
  LinkedList* tmp = this;

  if(m_next != NULL)
  {
    //->next twice because we want the node before the sentinel;
    while(tmp->m_next->m_next != NULL)
      tmp = tmp->m_next;
    
    return tmp;
  }
  else
  {
    std::cout << "PANIC in LinkedList.getLastPtr() - empty list" << std::endl;
    return NULL;
  }
}

template <class T>
LinkedList<T>* LinkedList<T>::getAtPtr(int i)
{
  LinkedList* tmp = this;

  //checks to make sure i is valid. runs through the list to i. tmp = &i
  if(!isEmpty() && i < size() && i >= 0)
  {
    for(int j = 0; j < i; j++)
      tmp = tmp->m_next;

    return tmp;
  }
  else
  {
    std::cout << "PANIC in LinkedList.getAtPtr() - invalid index" << std::endl;
  }
    return NULL;
}

template <class T>
void LinkedList<T>::clear()
{
  int sizeOf = size();
  LinkedList** pointers;
  LinkedList* tmp = m_next;

  if(sizeOf > 0)
  {
    pointers = new LinkedList*[sizeOf];
    //Stores the 2 node through the sentinel in the arraylist.
    for(int i = 0; i < sizeOf; i++)
    {
      pointers[i] = tmp;
      tmp = tmp->m_next;
    }
    
    //Deletes all the nodes. [2,sentinel]
    for(int i = 0; i < sizeOf; i ++)
      delete pointers[i];
  
    //Deletes the dynamically allocated array
    delete [] pointers;
  
    //First Node is now the sentinel
    m_next = NULL;
  }
  
  return;
}

template <class T>
void LinkedList<T>::insert_front(const T& x)
{
  LinkedList* tmp = new LinkedList;
  
  //Make the temp be the same as the last front item
  *tmp = *this;
  
  //Make the front item the new front item pointing to tmp, the new second itme.
  m_data = x;
  m_next = tmp;

  return;
}

template <class T>
void LinkedList<T>::insert(const T& x, LinkedList<T>* pos)
{
  LinkedList* tmp = new LinkedList;
  
  //Put temp in line after pos.
  tmp->m_next = pos->m_next;
  pos->m_next = tmp;

  //Make temp the value of pos m_data
  tmp->m_data = pos->m_data;
  
  //Make pos the value of x
  pos->m_data = x;
  
  return;
}

template <class T>
void LinkedList<T>::remove(LinkedList<T>* pos)
{
  LinkedList* tmp = pos->m_next;

  //make pos "jump" tmp, the next item in the list
  pos->m_next = tmp->m_next;

  //make pos->m_data the same has the one after it.
  pos->m_data = tmp->m_data;

  delete tmp;
  return;
}

template <class T>
bool LinkedList<T>::operator== (const LinkedList<T>& rhs) const
{
  LinkedList* tmpLhs = m_next;
  LinkedList* tmpRhs = rhs.m_next;

  //Lets first check if they are even the same size and the first element are the same.
  //Could possibly eliminate both size calls.
  if(this->size() == rhs.size() && this->m_data == rhs.m_data)
  {
    while(tmpLhs->m_next != NULL && tmpRhs != NULL)
    {
      //If they aren't equal just return false;
      if(tmpLhs->m_data != tmpRhs->m_data)
        return false;
      else //Transverse both lists
      {
        tmpLhs = tmpLhs->m_next;
        tmpRhs = tmpRhs->m_next;
      }
    }
      
    //If you get here then they were equal in every element.
    return true;
  }
  //They could be both empty so check that case.
  else if(this->size() == 0 && rhs.size() == 0)
    return true;
  else
    return false;
}

template <class T>
LinkedList<T>* LinkedList<T>::find(const T& x)
{
  LinkedList* tmp = this;
 
  //Traverses the list to find x 
  while(tmp->m_next != NULL)
  {
    if(tmp->m_data == x)
      return tmp; //returns the pointer to the object where x is FIRST found
    else
      tmp = tmp->m_next;
  }
  
  return NULL;
}

//May be faster to change the pointers? this traverses the list 3 times.
//Chaning pointers may traverse once.
template <class T>
void LinkedList<T>::reverse()
{
  int counter = -1;
  int sizeOf = size();
  T* data = new T[sizeOf];
  LinkedList* tmp = this;
  
  if(sizeOf > 1)
  {
    //Stop when tmp points to sentinel
    while(tmp->m_next != NULL)
    {
      counter ++; //Now the counter = 0;
      //Store each data point in this list.
      data[counter] = tmp->m_data;
      
      tmp = tmp->m_next;
    }
    
    //Start back at the beginning.
    tmp = this;
    
    //place the last number in the array at the front of the list.
    while(tmp->m_next != NULL)
    {
      //first is set to last element and so on.
      tmp->m_data = data[counter];
      counter --;

      tmp = tmp->m_next;
    }
  }

  delete [] data;
  return;
}

/*
template <class T>
void LinkedList<T>::reverse()
{
}
*/

template <class T>
void LinkedList<T>::append(const LinkedList<T>& xlist)
{
  LinkedList* tmp = this;
  LinkedList* append = new LinkedList;
  
  //copy xlist so that it can make a deep copy easily.
  *append = xlist;

  //go until the loop before the sentinel.  
  while(tmp->m_next->m_next != NULL)
    tmp = tmp->m_next;

  //delete the sentinel;
  delete tmp->m_next;

  tmp->m_next = append;

  return;
}
