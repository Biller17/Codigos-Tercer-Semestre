#include "TreeNode.h"

TreeNode::TreeNode(int _data)
{
	data = _data;
	left = nullptr;
	right = nullptr;
}

TreeNode::~TreeNode()
{
	left = nullptr;
	right = nullptr;
}

int TreeNode::getData()
{
	return data;
}

void TreeNode::setData(int _data)
{
	data = _data;
}

void TreeNode::setLeft(TreeNode * _left)
{
	left = _left;
}

TreeNode * TreeNode::getLeft()
{
	return left;
}

void TreeNode::setRight(TreeNode * _right)
{
	right = _right;
}

TreeNode * TreeNode::getRight()
{
	return right;
}