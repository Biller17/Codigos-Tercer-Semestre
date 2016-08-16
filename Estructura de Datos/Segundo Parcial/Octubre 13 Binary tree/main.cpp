#include <iostream>
#include "BinaryTree.h"

int main()
{
    int data[] = { 15, 7, 9, 20, 37, 3, 10, 17, 22 };
    int size = sizeof data / sizeof data[0];
    BinaryTree num_tree;
    
    for (int i = 0; i < size; i++)
    {
        num_tree.insertNode(data[i]);
    }
    num_tree.printInorder();
    
    int item = 7;
    if (num_tree.search(item))
        std::cout << "Found " << item << " in the tree" << std::endl;
    else
        std::cout << item << " is not in the tree" << std::endl;
    item = 30;
    if (num_tree.search(item))
        std::cout << "Found " << item << " in the tree" << std::endl;
    else
        std::cout << item << " is not in the tree" << std::endl;
}