#pragma once

#include <iostream>
#include "LinkedList.h"

template <class T>
class Vertex {
    private:
        T data;
        bool visited;
        LinkedList<Vertex *> neighbours;
    public:
        Vertex();
        Vertex(const T & _data);
        ~Vertex();
        T getData() { return data; }
        void setData(const T & _data) { data = _data; }
        void visit() { visited = true; }
        void unvisit() { visited = false; }
        bool isVisited() { return visited; }
        LinkedList<Vertex *> * getNeighbours() { return &neighbours; }
        //LinkedList<Vertex *> getNeighbours() { return neighbours; }
        void addNeighbour(Vertex * _neighbour);
};

template <class T>
Vertex<T>::Vertex()
{
    visited = false;
    neighbours = nullptr;
}

template <class T>
Vertex<T>::Vertex(const T & _data)
{
    data = _data;
    visited = false;
    neighbours = nullptr;
}

template <class T>
Vertex<T>::~Vertex()
{
    neighbours.~LinkedList();
    neighbours = nullptr;
}

template <class T>
void Vertex<T>::addNeighbour(Vertex * _neighbour)
{
    neighbours.insertTail(_neighbour);
}
