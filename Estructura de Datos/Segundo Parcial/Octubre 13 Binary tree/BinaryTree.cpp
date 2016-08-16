#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
    
}

BinaryTree::~BinaryTree()
{
}

void BinaryTree::insertNode(int _data)
{
    TreeNode * new_node = new TreeNode(_data);
    this->insertNode(new_node);
}

void BinaryTree::insertNode(TreeNode * _node)
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

TreeNode * BinaryTree::getRoot()
{
    return this->root;
}

void BinaryTree::setRoot(TreeNode * _root)
{
    
}

void BinaryTree::printInorder()
{
    if (this->root == nullptr)
        return;
    else
        recursivePrintInorder(this->root);
    std::cout << std::endl;
}

void BinaryTree::clear(TreeNode * _root)
{
    
}

void BinaryTree::recursiveInsert(TreeNode * _root, TreeNode * _node)
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

void BinaryTree::recursivePrintInorder(TreeNode * _root)
{
    if (_root == nullptr)
    {
        return;
    }
    
    recursivePrintInorder(_root->getLeft());
    std::cout << _root->getData() << "\t";
    recursivePrintInorder(_root->getRight());
}

bool BinaryTree::search(int _data)
{
    if (this->root == nullptr)
        return false;
    else
        return recursiveSearch(this->root, _data);
}

bool BinaryTree::recursiveSearch(TreeNode * _root, int _data)
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

TreeNode * BinaryTree::findMin(TreeNode *_root)
{
    if(_root->getLeft() ==nullptr)
        return _root;
    return findMin(_root->getLeft());
}

TreeNode * BinaryTree::recursiveRemove(TreeNode *_root, int _data)
{
    if(_root == nullptr)
        return nullptr;
    else if (_data < _root->getData())
    {
        _root->setLeft(recursiveRemove(_root->getLeft(), _data));
    }
    else
    {
        //Found the data, proceed to remove
        //case of leaf
        if(_root->getLeft() == nullptr && _root->getRight() == nullptr)
        {
            delete _root;
            return nullptr;
        }
        //case of left branch
        else if(_root->getRight() == nullptr)
        {
            TreeNode * left = _root->getLeft();
            delete _root;
            return left;
        }
        else if(_root->getLeft() == nullptr)
        {
            TreeNode * right = _root->getRight();
            delete _root;
            return right;
        }
        else
        {
            TreeNode * min = findMin(_root->getRight());
            _root->setData(min->getData());
            recursiveRemove(_root->getRight(), min->getData());
            return _root;
        }
    }
    return _root;
}


void BinaryTree::remove(int _data)
{
    if(this->root  == nullptr)
        return;
    this->root = recursiveRemove(this->root, _data);
}










