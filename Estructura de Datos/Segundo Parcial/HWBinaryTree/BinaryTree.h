#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include "TreeNode.h"
#include "Queue.h"

class BinaryTree {
private:
	TreeNode * root;
    Queue<TreeNode*> queue;

	void recursiveInsert(TreeNode * _root, TreeNode * _node);
	void recursivePrintInorder(TreeNode * _root);
	bool recursiveSearch(TreeNode * _root, int _data);
    TreeNode * recursiveRemove(TreeNode * _root, int _data);
    TreeNode * getMin(TreeNode * _root);
public:
	BinaryTree();
	~BinaryTree();
	void insertNode(int _data);
	void insertNode(TreeNode * _node);
	bool search(int _data);
	TreeNode * getRoot();
	void setRoot(TreeNode * _root);
	void printInorder();
    void printBreadthFirst();
	void clear(TreeNode * _root);
    void remove(int _data);
};

#endif
