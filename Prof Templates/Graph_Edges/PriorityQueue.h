/*
    Gilberto Echeverria

    Implementation of the PriorityQueue as a standalone class
*/

#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <iostream>

template <class T>
class PriorityQueue {
    protected:
        Node<T> * head = nullptr;
        int length = 0;
    public:
        // Constructors
        PriorityQueue () {}
        PriorityQueue (Node<T> * item) { head = item; }
        // Destructor
        ~PriorityQueue ();
        // PriorityQueue methods
        Node<T> * pop();
        Node<T> * top();
        void push(Node<T> * new_item);
        void push(const T & data);
		bool isEmpty();
        // Print the contents of the stack
        void printPriorityQueue();
        // Remove all nodes
        void clear();
};

/*
   Get the item that was last inserted into the stack
*/
template <class T>
Node<T> * PriorityQueue<T>::pop()
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
Node<T> * PriorityQueue<T>::top()
{
    return this->head;
}

template <class T>
void PriorityQueue<T>::push(Node<T> * new_item)
{
    // Special case when the list is empty
    //  or the new item is the smallest
    if ( this->head == nullptr || new_item->getData() < this->head->getData() )
    {
        // Make the new item point to the current head
        new_item->setNext(this->head);
        // Update the head
        this->head = new_item;
    }
    else
    {
        Node<T> * previous = this->head;
        Node<T> * item = previous->getNext();
        // Loop to search for the item
        while (item != nullptr && new_item->getData() > item->getData())
        {
            previous = item;
            item = item->getNext();
        }
        // Update the connections in the list
        new_item->setNext(item);
        previous->setNext(new_item);
    }
    // Increase the length of the list
    this->length++;

}

template <class T>
void PriorityQueue<T>::push(const T & data)
{
    Node<T> * item = new Node<T>(data);
    push(item);
}

template <class T>
bool PriorityQueue<T>::isEmpty()
{
	if (this->head == nullptr)
		return true;
	return false;
}

// Destructor
template <class T>
PriorityQueue<T>::~PriorityQueue()
{
    // Simply call the function to delete all nodes in the list
    this->clear();
}

/*
Simple function to print the contents of the PriorityQueue
*/
template <class T>
void PriorityQueue<T>::printPriorityQueue()
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
void PriorityQueue<T>::clear()
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
