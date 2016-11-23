#ifndef TREE_NODE_H
#define TREE_NODE_H

template <class T>
class TreeNode {
private:
	T data;
	TreeNode * left;
	TreeNode * right;
public:
    TreeNode ();
	TreeNode(T _data);
	~TreeNode();
	T getData();
	void setData(T _data);
	void setLeft(TreeNode * _left);
	TreeNode * getLeft();
	void setRight(TreeNode * _right);
	TreeNode * getRight();
};

template <class T>
TreeNode<T>::TreeNode(T _data)
{
	data = _data;
	left = nullptr;
	right = nullptr;
}

template <class T>
TreeNode<T>::~TreeNode()
{
	left = nullptr;
	right = nullptr;
}

template <class T>
T TreeNode<T>::getData()
{
	return data;
}

template <class T>
void TreeNode<T>::setData(T _data)
{
	data = _data;
}

template <class T>
void TreeNode<T>::setLeft(TreeNode<T> * _left)
{
	left = _left;
}

template <class T>
TreeNode<T> * TreeNode<T>::getLeft()
{
	return left;
}

template <class T>
void TreeNode<T>::setRight(TreeNode<T> * _right)
{
	right = _right;
}

template <class T>
TreeNode<T> * TreeNode<T>::getRight()
{
	return right;
}
#endif
