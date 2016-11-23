#pragma once

#include <iostream>
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "Vertex.h"

template <class T>
class Graph {
    private:
        LinkedList<Vertex<T>*> vertices;
        Vertex<T> * start;
    public:
        Graph();
        ~Graph();
        void addVertex(const T & _data);
        void addVertex(Vertex<T> * _vertex);
        void addEdge(const T & _origin, const T & _destination);
        void addEdge(Vertex<T> * _origin, Vertex<T> * _destination);
        void setStart(Vertex<T> * _start);
        Vertex<T> * getStart();
        void printBreathFirst();
        void printDepthFirst();
        void clearVisits();
};

template <class T>
Graph<T>::Graph()
{
    start = nullptr;
}

template <class T>
Graph<T>::~Graph()
{
    vertices.~LinkedList();
    vertices = nullptr;
}

template <class T>
void Graph<T>::addVertex(const T & _data)
{
    Vertex<T> * new_vertex = new Vertex<T>(_data);
    this->addVertex(new_vertex);
}

template <class T>
void Graph<T>::addVertex(Vertex<T> * _vertex)
{
    Node<Vertex<T> *> * node = new Node<Vertex<T> *>(_vertex);
    vertices.insertTail(node);
}

template <class T>
void Graph<T>::addEdge(const T & origin_data, const T & destination_data)
{
    Vertex<T> * _origin = nullptr;
    Vertex<T> * _destination = nullptr;
    Vertex<T> * current = nullptr;
    Node<Vertex<T> *> * node = vertices.getHead();
    // Look for the vertices that contain the data specified
    while (node != nullptr)
    {
        current = node->getData();
        if (current->getData() == origin_data)
            _origin = current;
        if (current->getData() == destination_data)
            _destination = current;
        node = node->getNext();
    }
    // Insert the vertices as neighbours
    if (_origin != nullptr && _destination != nullptr)
        _origin->addNeighbour(_destination);
}

template <class T>
void Graph<T>::addEdge(Vertex<T> * _origin, Vertex<T> * _destination)
{
    if (_origin != nullptr && _destination != nullptr)
        _origin->addNeighbour(_destination);
}

template <class T>
void Graph<T>::setStart(Vertex<T> * _start)
{
    start = _start;
}

template <class T>
Vertex<T> * Graph<T>::getStart()
{
    return start;
}

template <class T>
void Graph<T>::printBreathFirst()
{
    if (start == nullptr)
        return;

    Vertex<T> * current;
    Queue<Vertex<T> *> queue;
    Node<Vertex<T> *> * neighbour = nullptr;
    LinkedList<Vertex<T> *> * list = nullptr;

    std::cout << "Breadth First Traversal:" << std::endl;
    // Make sure all vertices are marked as not visited
    clearVisits();
    // Add the initial node to the queue
    queue.insert(start);
    while(!queue.isEmpty())
    {
        // Get the next vertex from the queue
        current = queue.remove()->getData();
        std::cout << current->getData() << " -> ";
        // Mark the vertex as visited
        current->visit();
        // Get the list of visited neighbours
        list = current->getNeighbours();
        // Starting from the first neighbour
        neighbour = list->getHead();
        while(neighbour != nullptr)
        {
            // If the neighbour has not been visited, add it to the queue
            if (!neighbour->getData()->isVisited())
            {
                queue.insert(neighbour->getData());
            }
            // Get next neighbour
            neighbour = neighbour->getNext();
        }
    }
    std::cout << std::endl;
}

template <class T>
void Graph<T>::printDepthFirst()
{
    if (start == nullptr)
        return;

    Vertex<T> * current;
    Stack<Vertex<T> *> stack;
    Node<Vertex<T> *> * neighbour = nullptr;
    LinkedList<Vertex<T> *> * list = nullptr;

    std::cout << "Depth First Traversal:" << std::endl;
    // Make sure all vertices are marked as not visited
    clearVisits();
    // Add the initial node to the stack
    stack.push(start);
    while(!stack.isEmpty())
    {
        // Get the next vertex from the stack
        current = stack.pop()->getData();
        std::cout << current->getData() << " -> ";
        // Mark the vertex as visited
        current->visit();
        // Get the list of visited neighbours
        list = current->getNeighbours();
        // Starting from the first neighbour
        neighbour = list->getHead();
        while(neighbour != nullptr)
        {
            // If the neighbour has not been visited, add it to the stack
            if (!neighbour->getData()->isVisited())
            {
                stack.push(neighbour->getData());
            }
            // Get next neighbour
            neighbour = neighbour->getNext();
        }
    }
    std::cout << std::endl;
}

template <class T>
void Graph<T>::clearVisits()
{
    Node<Vertex<T> *> * node = vertices.getHead();
    Vertex<T> * current;

    while(node != nullptr)
    {
        current = node->getData();
        current->unvisit();
        node = node->getNext();
    }
}
