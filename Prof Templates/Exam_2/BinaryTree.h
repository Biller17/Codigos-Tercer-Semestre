#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include "TreeNode.h"
#include "Queue.h"

template <class T>
class BinaryTree {
private:
	TreeNode<T> * root;
    Queue<TreeNode<T>*> queue;

	void recursiveInsert(TreeNode<T> * _root, TreeNode<T> * _node);
	void recursivePrintInorder(TreeNode<T> * _root);
	bool recursiveSearch(TreeNode<T> * _root, int _data);
	void recursiveClear(TreeNode<T> * _root);
    TreeNode<T> * recursiveRemove(TreeNode<T> * _root, int _data);
    TreeNode<T> * getMin(TreeNode<T> * _root);
public:
	BinaryTree();
	~BinaryTree();
	void insertNode(int _data);
	void insertNode(TreeNode<T> * _node);
	bool search(int _data);
	TreeNode<T> * getRoot();
	void setRoot(TreeNode<T> * _node);
	void printInorder();
    void printBreadthFirst();
    void remove(int _data);
	void clear();
};

template <class T>
BinaryTree<T>::BinaryTree()
{
    this->root = nullptr;
}

template <class T>
BinaryTree<T>::~BinaryTree()
{
    this->clear();
}

template <class T>
void BinaryTree<T>::insertNode(int _data)
{
	TreeNode<T> * new_node = new TreeNode<T>(_data);
	this->insertNode(new_node);
}

template <class T>
void BinaryTree<T>::insertNode(TreeNode<T> * _node)
{
	if (this->root == nullptr)
	{
		this->root = _node;
	}
	else
	{
		recursiveInsert(this->root, _node);
	}
}

template <class T>
TreeNode<T> * BinaryTree<T>::getRoot()
{
	return this->root;
}

template <class T>
void BinaryTree<T>::setRoot(TreeNode<T> * _node)
{
    this->root = _node;
}

template <class T>
void BinaryTree<T>::printInorder()
{
	if (this->root == nullptr)
		return;
	else
		recursivePrintInorder(this->root);
	std::cout << std::endl;
}

template <class T>
void BinaryTree<T>::recursiveClear(TreeNode<T> * _root)
{
    if (_root == nullptr)
        return;
    recursiveClear(_root->getLeft());
    recursiveClear(_root->getRight());
    delete _root;
}

template <class T>
void BinaryTree<T>::clear()
{
    // Do nothing for an empty tree
    if (this->root == nullptr)
        return;
    // Clear recursively
    recursiveClear(this->root);
    // State that the tree is empty
    this->root = nullptr;
}

template <class T>
void BinaryTree<T>::recursiveInsert(TreeNode<T> * _root, TreeNode<T> * _node)
{
	if (_root->getData() == _node->getData())
	{
		return;
	}
	// Node goes on the left branch
	else if (_node->getData() < _root->getData())
	{
		if (_root->getLeft() == nullptr)
		{
			_root->setLeft(_node);
		}
		else
		{
			recursiveInsert(_root->getLeft(), _node);
		}
	}
	// Node goes on the right branch
	else if (_node->getData() > _root->getData())
	{
		if (_root->getRight() == nullptr)
		{
			_root->setRight(_node);
		}
		else
		{
			recursiveInsert(_root->getRight(), _node);
		}
	}
}

template <class T>
void BinaryTree<T>::recursivePrintInorder(TreeNode<T> * _root)
{
	if (_root == nullptr)
	{
		return;
	}

	recursivePrintInorder(_root->getLeft());
	std::cout << _root->getData() << "\t";
	recursivePrintInorder(_root->getRight());
}

template <class T>
bool BinaryTree<T>::search(int _data)
{
	if (this->root == nullptr)
		return false;
	else
		return recursiveSearch(this->root, _data);
}

template <class T>
bool BinaryTree<T>::recursiveSearch(TreeNode<T> * _root, int _data)
{
	if (_root->getData() == _data)
		return true;
	else
	{
		if (_data < _root->getData())
		{
			if (_root->getLeft() == nullptr)
				return false;
			return recursiveSearch(_root->getLeft(), _data);
		}
		else
		{
			if (_root->getRight() == nullptr)
				return false;
			return recursiveSearch(_root->getRight(), _data);
		}
	}
}

template <class T>
TreeNode<T> * BinaryTree<T>::getMin(TreeNode<T> * _root)
{
    if (_root->getLeft() == nullptr)
        return _root;
    else
        return getMin(_root->getLeft());
}

template <class T>
TreeNode<T> * BinaryTree<T>::recursiveRemove(TreeNode<T> * _root, int _data)
{
    if (_root == nullptr)
        return nullptr;
    if (_data < _root->getData())
    {
        _root->setLeft( recursiveRemove(_root->getLeft(), _data) );
    }
    else if (_data > _root->getData())
    {
        _root->setRight( recursiveRemove(_root->getRight(), _data) );
    }
    // The data is found in the root
    else
    {
        // Node has no children
        if (_root->getLeft() == nullptr && _root->getRight() == nullptr)
        {
            std::cout << "Deleting leaf" << std::endl;
            delete _root;
            _root = nullptr;
        }
        // Node has only left child
        else if (_root->getRight() == nullptr)
        {
            std::cout << "Deleting with only left branch" << std::endl;
            TreeNode<T> * tmp = _root;
            _root = _root->getLeft();
            delete tmp;
        }
        // Node has only right child
        else if (_root->getLeft() == nullptr)
        {
            std::cout << "Deleting with only right branch" << std::endl;
            TreeNode<T> * tmp = _root;
            _root = _root->getRight();
            delete tmp;
        }
        // Node has both children
        else
        {
            std::cout << "Deleting with both branches" << std::endl;
            TreeNode<T> * tmp = getMin(_root->getRight());
            _root->setData(tmp->getData());
            _root->setRight(recursiveRemove(_root->getRight(), tmp->getData()));
        }
    }
    // Return the current root so that it is updated in previous recursive calls
    return _root;
}

template <class T>
void BinaryTree<T>::remove(int _data)
{
    if (this->root == nullptr)
        return;
    this->root = recursiveRemove(this->root, _data);
}

template <class T>
void BinaryTree<T>::printBreadthFirst()
{
    if (this->root == nullptr)
        return;
    TreeNode<T> * item;
    queue.insert(this->root);
    while (!queue.isEmpty())
    {
        item = queue.remove()->getData();
        std::cout << item->getData() << "\t";
        if (item->getLeft() != nullptr)
            queue.insert(item->getLeft());
        if (item->getRight() != nullptr)
            queue.insert(item->getRight());
    }
    std::cout << std::endl;
}
#endif
