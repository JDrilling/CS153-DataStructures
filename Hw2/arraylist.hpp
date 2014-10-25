/*Jacob Drilling
 *CS-153; Section A; HW2
 *File: ArrayList.hpp
 *Implementation of ArrayList.h
 */

const int START_SIZE = 2; //Size of a newly created array.

//--------Basic Accessor Operations-----//
template <typename T>
ArrayList<T>::~ArrayList()
{
  m_size = 0;
  m_max = 0;
  delete [] m_data;
  m_data = NULL;
}

template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& rhs)
{
  if(this != &rhs)
  {
    m_size = rhs.m_size;
    m_max = rhs.m_max;
    m_errobj = rhs.m_errobj;
  
    delete [] m_data;
    m_data = new T[rhs.m_max];

  for(int i = 0; i < rhs.m_size;i++)
    m_data[i] = rhs.m_data[i];

  }

  return *this;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T>& cpy)
{
  m_data = NULL;
  *this = cpy;
}

/*-------- Basic Accessor Operations ------ */

template <typename T>
int ArrayList<T>::size() const {return m_size;}

template <typename T> 
const T& ArrayList<T>::first() const 
{ 
  if (m_size > 0)
    return m_data[0];
  else
  {
    std::cout << "!-- ERROR : PANIC in ARRAYLIST.first()!!"  
              << "  (List is empty)" << std::endl;
    return m_errobj;
  }
}

template <typename T>
T& ArrayList<T>::operator[](int i)
{
  if ( i >=0 && i < m_size)
    return m_data[i];
  else
  {
    std::cout << "!-- ERROR : PANIC in ARRAYLIST!!.[]"
              << "  (index out of bounds)" << std::endl;
    return m_errobj;
  }

}

template <typename T>
const T& ArrayList<T>::operator[](int i) const
{
  if ( i >=0 && i < m_size)
    return m_data[i];
  else
  {
    std::cout << "!-- ERROR : PANIC in ARRAYLIST!!.[]"
              << "  (index out of bounds)" << std::endl;
    return m_errobj;
  }
}


template <typename T>
int ArrayList<T>::find(const T& x)
{
  for(int i = 0; i < m_size; i ++)
    if ( m_data[i] == x)
      return i;

  return -1;
}

/* ----- Basic Mutator Operations ----- */

template <typename T>
void ArrayList<T>::clear()
{
  m_size = 0;
  m_max = 0;
  delete [] m_data;
  m_data = NULL;
}

template <typename T>
void ArrayList<T>::insert_back(const T& x)
{
  T* temp;
  //-----------Check If an Array has been created yet--------//
  if(m_max == 0)
  {
    m_data = new T[START_SIZE];
    m_max = START_SIZE;
  }
  //-----------Check if the current array is full------------//
  else if (m_size >= m_max)
  {
    temp = new T[2 * m_max];
    for (int i = 0; i < m_size; i++)
      temp[i] = m_data[i];

    delete [] m_data;

    m_data = temp;
    m_max *= 2;
  }
 
  m_data[m_size] = x;
  m_size ++;
}

template <typename T>
void ArrayList<T>::insert(const T& x, int i)
{
  T* temp;

  if(i >= 0 && i < m_size)
  {
    if (m_size >= m_max)
    {
      temp = new T[2 * m_max];
      for (int j = 0; j < m_size; j++)
        temp[j] = m_data[j];
  
      delete [] m_data;
  
      m_data = temp;
      m_max *= 2;
    }
    
    for(int j = m_size; j > i; j--)
      m_data[j] = m_data[j-1];
    
    m_data[i] = x;
    m_size ++;  
  }
  else
    std::cout << "!-- ERROR : PANIC in ARRAYLIST!!.insert()"
              << "  (index out of bounds)" << std::endl;
}

template <typename T>
void ArrayList<T>::remove(int i)
{
  T* temp;

  if( i < m_size && i >= 0)
  {
    for (int j = i; j < m_size - 1; j++)
      m_data[j] = m_data[j+1];
    
    if (m_size > 0)
      m_size --;
  
    if(m_size < m_max / 4)
    {
      temp = new T[m_max/2];
      for(int j = 0; j < m_size; j++)
        temp[j] = m_data[j];
      
      delete [] m_data;
      m_data = temp;
      m_max /= 2;
    }
  }
  else
    std::cout << "!-- ERROR : PANIC in ARRAYLIST!!.remove()"
              << "  (index out of bounds)" << std::endl;

}

template <typename T>
void ArrayList<T>::swap(int i, int k)
{
  T temp;
  if (i >= 0 && i < m_size && k >= 0 && k < m_size)
  {  
    temp = m_data[i];
    m_data[i] = m_data[k];
  
    m_data[k] = temp;
  }
  else
    std::cout << "!-- ERROR : PANIC in ARRAYLIST!!.swap()"
              << "  (index out of bounds)" << std::endl;
}

template <typename T>
void ArrayList<T>::append(const ArrayList<T>& alist)
{
  for( int i = 0; i < alist.size(); i++)
    insert_back(alist[i]);
}

template <typename T>
void ArrayList<T>::purge()
{
  for(int i = 0; i < m_size - 1; i++)
    for(int j = i + 1; j < m_size; j++)
      if( m_data[i] == m_data[j])
        remove(j);
}
