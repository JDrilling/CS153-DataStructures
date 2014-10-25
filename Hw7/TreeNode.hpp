

template <typename T>
TreeNode<T>::TreeNode(const T& x, TreeNode<T>* left, TreeNode<T>* right)
{
  m_left = left;
  m_right = right;
  m_data = x;
}

template <typename T>
TreeNode<T>::TreeNode( TreeNode<T>* left, TreeNode<T>* right)
{
  m_left = left;
  m_right = right;
}


template <typename T>
void prettyPrint (const TreeNode<T>* t, int pad = 0)
{
 string s(pad, ' ');
 if (t == NULL)
     cout << s << endl;
 else{
   prettyPrint(t->m_right, pad+4);
   cout << s << t->m_data << endl;
   prettyPrint(t->m_left, pad+4);
 }  
}


template <typename T>
void insertNode(TreeNode<T>* &t, const T &x)
{
  if(t == NULL)
  {
    t = new TreeNode<T>(x, NULL,NULL);
  }
  else if( x < t->m_data)
    insertNode(t->m_left, x);
  else if( x > t->m_data)
    insertNode(t->m_right, x);
  else
    return;
  
}

template <typename T>
int nodeHeight(TreeNode<T>* t)
{
  int lHeight, rHeight;
  
  if (t == NULL)
    return 0;
  else
  {
    lHeight = nodeHeight(t->m_left);
    rHeight = nodeHeight(t->m_right);
    
    if(lHeight > rHeight)
      return lHeight + 1;
    else
      return rHeight + 1;
  }
}

template <typename T>
const T& nodeMax(TreeNode<T>* t)
{
  if(t->m_right == NULL)
    return t->m_data;
  else
    return nodeMax(t->m_right);
}

template <typename T>
const T& nodeMin(TreeNode<T>* t)
{
  if(t->m_left == NULL)
    return t->m_data;
  else
    return nodeMin(t->m_left);
}

template <typename T>
void clearNode(TreeNode<T>* t)
{

  if(t->m_right != NULL)
  {
    clearNode(t->m_right);
    delete t->m_right;
  }
  if(t->m_left != NULL)
  {
    clearNode(t->m_left);
    delete t->m_left;
  }
}

template <typename T>
void copyNodes( TreeNode<T>* &lhs  , const TreeNode<T>* rhs)
{
  if(lhs == NULL)
    lhs = new TreeNode<T>(rhs->m_data,NULL,NULL);
  else
    lhs->m_data = rhs->m_data;
  
  if(rhs->m_right != NULL)
    copyNodes(lhs->m_right, rhs->m_right);
  if(rhs->m_left != NULL)
    copyNodes(lhs->m_left, rhs->m_left);
}

template <typename T>
void removeNode(TreeNode<T>* &t, const T& x)
{
  TreeNode<T>* tmp;
  
  if(t == NULL)
    return;
  else if(t->m_data < x)
    removeNode(t->m_right, x);
  else if(t->m_data > x)
    removeNode(t->m_left, x);
  else // m_data == x
  {
    if (t->m_right == NULL && t->m_left == NULL) //empty tree
    {
      delete t;
      t = NULL;
    }
    else if(t->m_right == NULL) //only a left child
    {
      tmp = t;
      t = t->m_left;
      delete tmp;
    }
    else if(t->m_left == NULL) //only a right child
    {
      tmp = t;
      t = t->m_right;
      delete tmp;
    }
    else // must have 2 children
    {
      t->m_data = nodeMax(t->m_left); // or min of right
      removeNode(t->m_left, t->m_data); // will now hunt and remove max of left side.
    }
  }
}

template <typename T>
void printPre(TreeNode<T>* t)
{
  cout << t->m_data << endl;
  
  if(t->m_left != NULL)
    printPre(t->m_left);
  if(t->m_right !=NULL)
    printPre(t->m_right);
}

template <typename T>
void printPost(TreeNode<T>* t)
{
  
  if(t->m_left != NULL)
    printPost(t->m_left);
  if(t->m_right !=NULL)
    printPost(t->m_right);
    
  cout << t->m_data << endl;
}

template <typename T>
int nodeContains(TreeNode<T>* t, const T& x, int depth = 0) 
{
  if(t == NULL)
    return (depth - 1)*-1;
  if(t->m_data == x)
    return depth;
  else
  {
    if(x > t->m_data)
       return nodeContains(t->m_right, x, depth + 1);
    else if(x < t->m_data)
      return nodeContains(t->m_left, x, depth + 1);
  }
    
}








