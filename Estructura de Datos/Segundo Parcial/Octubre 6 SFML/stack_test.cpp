/*
   Gilberto Echeverria

   Sample program to use the Stack list library
*/

#include <iostream>
#include "Stack.h"

int main(void)
{
    Stack<std::string> test_stack;
    Node<std::string> * item = nullptr;
    std::string * tmp_string;
    int i;

    std::cout << "Initial length: " << test_stack.getLength() << std::endl;

    tmp_string = new std::string("Mercury");
    test_stack.push(*tmp_string);
    tmp_string = new std::string("Venus");
    test_stack.push(*tmp_string);
    tmp_string = new std::string("Mars");
    test_stack.push(*tmp_string);
    tmp_string = new std::string("Earth");
    test_stack.push(*tmp_string);
    tmp_string = new std::string("Jupiter");
    test_stack.push(*tmp_string);
    tmp_string = new std::string("Saturn");
    test_stack.push(*tmp_string);

    std::cout << "New length: " << test_stack.getLength() << std::endl;
    std::cout << "This is the stack now: " << std::endl;
    test_stack.printList();

    item = test_stack.pop();
    std::cout << "Item popped out: " << item->getData() << std::endl;
    delete item;
    item = test_stack.pop();
    std::cout << "Item popped out: " << item->getData() << std::endl;
    delete item;
    item = test_stack.pop();
    std::cout << "Item popped out: " << item->getData() << std::endl;
    delete item;

    std::cout << "New length: " << test_stack.getLength() << std::endl;
    std::cout << "This is the stack now: " << std::endl;
    test_stack.printList();


    return 0;
}
