/* Jacob Drilling
 * Section A 
 * robotcalc.cpp
 */


#include <iostream>
#include <cstdlib>
#include "AbstractStack.h"
using namespace std;

template <typename T>
class LinkedStack: public AbstractStack<T>
{
  public:
    LinkedStack(): m_next(NULL){};

    void clear();
    
    void push(const T& x);
    
    void pop();
    
    const T& top() const throw (string);
    
    bool isEmpty() const;

    void print() const;
    
    LinkedStack<T>* m_next;
    T m_data;
};

template <typename T>
void LinkedStack<T>::print() const
{
  LinkedStack* tmp = m_next;

  cout << "[ ";

  if(m_next != NULL)
  {
    cout << m_data;
    if(tmp->m_next != NULL)
      cout << ", ";
    
    while(tmp->m_next != NULL)
    {
      cout << tmp->m_data;
      tmp = tmp->m_next;
      
      if(tmp->m_next != NULL)
        cout << ", ";
    }
  }
  cout << " ]";

  tmp = NULL;
  return;
}

template <typename T>
void LinkedStack<T>::clear()
{
  LinkedStack* tmp = this;
  LinkedStack* next = tmp->m_next;
  
  while (next != NULL)
  {
    tmp = next;
    next = next->m_next;
    delete tmp;
  }

  tmp = NULL;
  next = NULL;
  
  m_next = NULL;
  return;
}

template<typename T>
void LinkedStack<T>::push(const T& x)
{
  LinkedStack* tmp = new LinkedStack;
  
  //Puts the new node in line as 2nd element
  tmp->m_next =  m_next;
  m_next = tmp;
  
  // puts old 1st data in the 2nd position
  tmp->m_data = m_data;
  m_data = x;

  tmp = NULL;
}

template<typename T>
void LinkedStack<T>::pop()
{
  LinkedStack* tmp = m_next;
  if(m_next != NULL)
  {
    //Top is deleted by overwriting it with 2nd cell data;
    m_data = m_next->m_data;
    m_next = m_next->m_next;

    //2nd cell is deleted
    delete tmp;
  }

  tmp = NULL;
}

template <typename T>
const T& LinkedStack<T>::top() const throw (string)
{
  string error = "Stack is empty! Could not perform operation.";

  if(!isEmpty())
    return m_data;
  else
    throw error;
}

template <typename T>
bool LinkedStack<T>::isEmpty() const
{
  if(m_next == NULL)
    return true;
  else
    return false;
}

int main()
{
  string input;
  int x, y;
  LinkedStack<int> robotStack;
  bool quit = false;

  do
  { 
    try{
      cin >> input;
      if(input == "sum")
      {
        if(!robotStack.isEmpty())
        {
          x = robotStack.top();
          robotStack.pop();
            
          while(!robotStack.isEmpty())
          {
            y = robotStack.top();
            robotStack.pop();
            x += y;
          }
          robotStack.push(x);
        }
  
      }else if(input == "prod")
      {
        if(!robotStack.isEmpty())
        {
          x = robotStack.top();
          robotStack.pop();
            
          while(!robotStack.isEmpty())
          {
            y = robotStack.top();
            robotStack.pop();
            x *= y;
          }
          robotStack.push(x);
        }
  
      }else if(input == "@")
      {
        quit = true;
      }else if(input == "#")
      {
        robotStack.print();
        cout << endl;
      }else if(input == "$")
      {
        robotStack.clear();
      }else if(input == "!")
      {
        x = robotStack.top();
        robotStack.pop();
  
        x *= -1;
        robotStack.push(x);
      }else if(input == "*")
      {
        x = robotStack.top();
        robotStack.pop();
        y = robotStack.top();
        robotStack.pop();
  
        robotStack.push(x*y);
      }else if(input == "%")
      {
        x = robotStack.top();
        robotStack.pop();
        y = robotStack.top();
        robotStack.pop();
  
        try
        {
          if(x == 0)
            throw string("Could not mod by zero");
          else
            robotStack.push(y%x);
        }
        catch(string error)
        {
          cout << error << endl;
          robotStack.clear();
          cout << "Stack has bee cleard." << endl;
        }
  
      }else if(input == "/")
      { 
        x = robotStack.top();
        robotStack.pop();
        y = robotStack.top();
        robotStack.pop();

        try
        {          
          if( x == 0)
            throw string("Could not divide by Zero");
          else
            robotStack.push(y/x);
        }
        catch(string error)
        {
          cout << error << endl;
          robotStack.clear();
          cout << "Stack has been cleared." << endl;
        }
  
      }else if(input == "+")
      {
        x = robotStack.top();
        robotStack.pop();
        y = robotStack.top();
        robotStack.pop();
  
        robotStack.push(x+y);
  
      }else if(input == "-")
      {
        x = robotStack.top();
        robotStack.pop();
        y = robotStack.top();
        robotStack.pop();
  
        robotStack.push(y-x);
  
      }else //I guess we have to assume its a number.
      {
        x = atoi(input.c_str());
        robotStack.push(x);
      }
    
    }
    catch(string error)
    {
      cout << error << endl;
      robotStack.clear();
      cout << "Stack has been clearted." << endl;
    }    
  }while(!quit);
  
  robotStack.clear();
  return 0;
}
