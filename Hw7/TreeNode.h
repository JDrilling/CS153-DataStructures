#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
using namespace std;

template <typename T>
struct TreeNode
{   
    TreeNode(const T& x, TreeNode<T>* left, TreeNode<T>* right);
    TreeNode(TreeNode<T>* left, TreeNode<T>* right);

    T m_data;
    TreeNode* m_left;
    TreeNode* m_right;
};


//Pre: pad = 0 when called.
template<typename T>
void prettyPrint (const TreeNode<T>* t, int pad = 0);


template<typename T>
void insertNode(TreeNode<T>* &t, const T &x);


template<typename T>
int nodeHeight(TreeNode<T>* t);

template <typename T>
const T& nodeMax(TreeNode<T>* t);

template <typename T>
const T& nodeMin(TreeNode<T>* t);

template <typename T>
void clearNode(TreeNode<T>* t);

//pre: Lhs must be an empty tree.
template <typename T>
void copyNodes(TreeNode<T>* &lhs , const TreeNode<T>* rhs);

template <typename T>
void removeNode(TreeNode<T>* &t, const T& x);

template <typename T>
void printPre(TreeNode<T>* t);

template <typename T>
void printPost(TreeNode<T>* t);

template <typename T>
int nodeContains(TreeNode<T>* t, const T& x, int depth = 0);

#include "treenode.hpp"



#endif