/*
    Gilberto Echeverria

    Implementation of a Queue
*/

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "Node.h"

template <class T>
class Queue {
    private:
        Node<T> * head;
        Node<T> * tail;
    public:
        Queue() { head = nullptr; tail = nullptr; }
        Node<T> * remove();
        void insert(Node<T> * new_item);
        void insert(const T & data);
		bool isEmpty();
};

/*
   Get the item that was first inserted into the queue
   Always will be the item at the head
*/
template <class T>
Node<T> * Queue<T>::remove()
{
    // Check for an empty queue
    if (this->head == nullptr)
        return nullptr;
    // Check if there is only one item
    if (this->head == this->tail)
        this->tail = nullptr;
    Node<T> * tmp = this->head;
    this->head = this->head->getNext();
    tmp->setNext(nullptr);
    return tmp;
}

/*
   Insert all new items at the tail of the queue
*/
template <class T>
void Queue<T>::insert(Node<T> * new_item)
{
    // Check for an empty queue
    if (this->tail == nullptr)
    {
        this->head = new_item;
        this->tail = new_item;
    }
    // Otherwise update the tail
    else
    {
        this->tail->setNext(new_item);
        this->tail = new_item;
    }
}

template <class T>
void Queue<T>::insert(const T & data)
{
    Node<T> * item = new Node<T>(data);
    insert(item);
}

template <class T>
bool Queue<T>::isEmpty()
{
	if (this->head == nullptr)
		return true;
	return false;
}
#endif
