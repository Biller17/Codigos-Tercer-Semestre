#pragma once

#include <iostream>
#include "LinkedList.h"
#include "Edge.h"

template <class T, class W>
class Vertex {
    private:
        T data;
        bool visited;
        LinkedList<Edge<T, W> *> edges;
    public:
        Vertex();
        Vertex(const T & _data);
        ~Vertex();
        T getData() { return data; }
        void setData(const T & _data) { data = _data; }
        void visit() { visited = true; }
        void unvisit() { visited = false; }
        bool isVisited() { return visited; }
        LinkedList<Edge<T, W> *> * getEdges() { return &edges; }
        void addEdge(Edge<T, W> * _edge);

        template <class R, class S>
        friend std::ostream & operator<< (std::ostream & stream, const Vertex<R, S> & vertex);
};

template <class T, class W>
Vertex<T, W>::Vertex()
{
    visited = false;
    edges = nullptr;
}

template <class T, class W>
Vertex<T, W>::Vertex(const T & _data)
{
    data = _data;
    visited = false;
    edges = nullptr;
}

template <class T, class W>
Vertex<T, W>::~Vertex()
{
    edges.~LinkedList();
    edges = nullptr;
}

template <class T, class W>
void Vertex<T, W>::addEdge(Edge<T, W> * _edge)
{
    edges.insertTail(_edge);
}

template <class T, class W>
std::ostream & operator<< (std::ostream & stream, const Vertex<T, W> & vertex)
{
    stream << "Data: " << vertex.data << " | " << (vertex.visited ? "" : "not ") << "visited";
    return stream;
}
