#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "TreeNode.h"
#include <iostream>

class BinaryTree {
private:
    TreeNode * root;
    
    void recursiveInsert(TreeNode * _root, TreeNode * _node);
    void recursivePrintInorder(TreeNode * _root);
    bool recursiveSearch(TreeNode * _root, int _data);
    TreeNode * recursiveRemove(TreeNode* _root, int data);
    TreeNode * findMin(TreeNode * _root);
public:
    BinaryTree();
    ~BinaryTree();
    void insertNode(int _data);
    void insertNode(TreeNode * _node);
    bool search(int _data);
    TreeNode * getRoot();
    void setRoot(TreeNode * _root);
    void printInorder();
    void clear(TreeNode * _root);
    void remove(int _data);
};

#endif