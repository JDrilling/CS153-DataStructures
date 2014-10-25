/* Jacob Drilling.
 * maxHeap.hpp
 * function definitions of maxHeap.h
  */
  
template <typename T>
maxHeap<T>& maxHeap<T>::operator=(const maxHeap<T>& rhs)
{
  if(this != &rhs)
  {
    m_size = rhs.m_size;
    m_max = rhs.m_max;
  
    delete [] m_data;
    m_data = new T[rhs.m_max];

  for(int i = 0; i < rhs.m_size + 1;i++)
    m_data[i] = rhs.m_data[i];

  }

  return *this;
}

template <typename T>
maxHeap<T>::maxHeap(const maxHeap<T>& cpy)
{
  m_data = NULL;
  *this = cpy;
}

template <typename T>
const T& maxHeap<T>::top() const throw (string)
{
  if(m_size == 0)
    throw string("Could not return top. Heap is empty!");
    
  return m_data[1];
} 

template <typename T>
void maxHeap<T>::clear() 
{

  m_size = 0;
  m_max = 0;
  delete [] m_data;
  m_data = NULL;
  
  return;
  
  
}

template <typename T>
void maxHeap<T>::insert(const T& x) 
{
    T* temp;
  //-------Array Created?-----//
  if(m_max == 0)
  {
    m_data = new T[3];
    m_max = 3;
  }
  //--------Array Full? full is max - 1 due to space at 0---------//
  else if (m_size >= m_max - 1)
  {
    temp = new T[2 * m_max - 1];
    for (int i = 0; i < m_size + 1; i++)
      temp[i] = m_data[i];

    delete [] m_data;

    m_data = temp;
    
    m_max *= 2;
    m_max --;
  }
  
  int hole;
  m_size ++;
  hole = m_size;
  while(hole > 1 && x > m_data[hole/2])
  {
    m_data[hole] = m_data[hole/2];
    hole = hole/2;
  }
  
  m_data[hole] = x;

}

template <typename T>
void maxHeap<T>::remove() 
{
  if(m_size > 0)
  {
    
    T tmp = m_data[m_size];
    m_size --;
    int hole = 1;
    bool quit = false;
    
    while(hole*2 < m_size + 1 && !quit)
    {
      int child = hole *2;
      if(child < m_size && m_data[child + 1] > m_data[child])
        child ++;
      if(m_data[child] > tmp)
      {
        m_data[hole] = m_data[child];
        hole = child;
      }
      else
        quit = true;
    }
    m_data[hole] = tmp;
    
    
    //Resize if too big.
    if(m_size < (m_max - 1) / 4)
    {
      T* temp = new T[m_max/2 + 1];
      for(int j = 0; j < m_size + 1; j++)
        temp[j] = m_data[j];
      
      delete [] m_data;
      m_data = temp;
      m_max /= 2;
      m_max ++;
    }
  }
}


template<typename T>
void prettyPrint (int  ix, int pad, int m_size, T* m_data)
{
 string s(pad, ' ');
 if (ix > m_size)
     cout << endl;
 else{
   prettyPrint( ix*2 + 1, pad+4, m_size, m_data);
   cout << s << m_data[ix] << endl;
   prettyPrint( ix*2, pad+4, m_size, m_data);
 }  
}