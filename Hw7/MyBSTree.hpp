
template <typename T>
void MyBSTree<T>::insert(const T& x)
{
  if(m_size == 0)
    m_root->m_data = x;
  else
    insertNode(m_root, x);
    
  m_size ++;
}

template <typename T>
const T& MyBSTree<T>::findMax() const throw (string)
{
  if(m_size == 0)
    throw string("Error: Tree is empty!");
    
  return nodeMax(m_root);
}

template <typename T>
const T& MyBSTree<T>::findMin() const throw (string)
{
  if(m_size == 0)
    throw string("Error: Tree is empty!");
  
  return nodeMin(m_root);
}

template <typename T>
void MyBSTree<T>::clear()
{
  
  if(m_root != NULL)
  {
    clearNode(m_root); 
    m_size = 0; 
  }
}

template <typename T>
MyBSTree<T>& MyBSTree<T>::operator =(const MyBSTree<T>& rhs)
{
  this->clear();
  
  m_size = rhs.m_size;
  
  if(rhs.m_size > 0)
    copyNodes(this->m_root, rhs.m_root);

  return *this;
}

template <typename T>
void MyBSTree<T>::remove(const T& x)
{
  if(m_size > 0)
  {
    removeNode(m_root, x);
    m_size --;
  }
}

template <typename T>
int MyBSTree<T>::contains(const T& x) const
{
  if(m_size > 0)
    return nodeContains(m_root, x);
  else
    return 0;
}