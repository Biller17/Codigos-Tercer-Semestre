/*
    Gilberto Echeverria

    Implementation of the Stack as a standalone class
*/

#ifndef STACK_H
#define STACK_H

#include <iostream>

template <class T>
class Stack {
    protected:
        Node<T> * head = nullptr;
        int length = 0;
    public:
        // Constructors
        Stack () {}
        Stack (Node<T> * item) { head = item; }
        // Destructor
        ~Stack ();
        // Stack methods
        Node<T> * pop();
        Node<T> * top();
        void push(Node<T> * new_item);
        void push(const T & data);
		bool isEmpty();
        // Print the contents of the stack
        void printStack();
        // Remove all nodes
        void clear();
};

/*
   Get the item that was last inserted into the stack
*/
template <class T>
Node<T> * Stack<T>::pop()
{
    Node<T> * item = this->head;

    // Check that the list is not empty
    if (this->head != nullptr)
    {
        // Make the head point to the second item
        this->head = item->getNext();
        // Make the item point to nothing
        item->setNext(nullptr);
        // Reduce the length of the list
        this->length--;
    }

    return item;
}

template <class T>
Node<T> * Stack<T>::top()
{
    return this->head;
}


template <class T>
void Stack<T>::push(Node<T> * new_item)
{
    // Make this node point to the previous head
    new_item->setNext(this->head);
    // The node becomes the head of the list
    this->head = new_item;
    // Increment the size of the list
    this->length++;

}

template <class T>
void Stack<T>::push(const T & data)
{
    Node<T> * item = new Node<T>(data);
    push(item);
}

template <class T>
bool Stack<T>::isEmpty()
{
	if (this->head == nullptr)
		return true;
	return false;
}

// Destructor
template <class T>
Stack<T>::~Stack()
{
    // Simply call the function to delete all nodes in the list
    this->clear();
}

/*
Simple function to print the contents of the Stack
*/
template <class T>
void Stack<T>::printStack()
{
    Node<T> * item;
    int counter = 0;

    item = this->head;
    while (item != nullptr)
    {
        std::cout << "Item " << counter++ << " = " << item->getData() << std::endl;
        item = item->getNext();
    }
}

/*
Empty the list, and free the memory for all nodes
*/
template <class T>
void Stack<T>::clear()
{
    Node<T> * item;

    item = this->head;
    while (item != nullptr)
    {
        std::cout << "Deleting item " << item->getData() << std::endl;
        this->head = item->getNext();
        delete item;
        item = this->head;
    }
    this->length = 0;
    this->head = nullptr;
}
#endif
