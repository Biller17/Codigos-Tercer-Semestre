/*
    Gilberto Echeverria

    Implementation of the Stack as a subclass of LinkedList
*/

#include <iostream>
#include "LinkedList.h"

template <class T>
class Stack : public LinkedList<T> {
    public:
        Node<T> * pop();
        void push(Node<T> * new_item);
        void push(const T & data);
};

/*
   Get the item that was last inserted into the stack
*/
template <class T>
Node<T> * Stack<T>::pop()
{
    return LinkedList<T>::removeHead();
}

template <class T>
void Stack<T>::push(Node<T> * new_item)
{
    LinkedList<T>::insertHead(new_item);
}

template <class T>
void Stack<T>::push(const T & data)
{
    Node<T> * item = new Node<T>(data);
    LinkedList<T>::insertHead(item);
}
