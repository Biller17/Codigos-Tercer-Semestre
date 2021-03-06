#pragma once

#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include "Vertex.h"
#include "InfoNode.h"

template <class T, class W>
class Graph {
    private:
        std::list<Vertex<T, W> *> vertices;
        std::list<Edge<T, W> *> edges;
        Vertex<T, W> * start;
    public:
        Graph() { start = nullptr; }
        ~Graph();
        void addVertex(const T & _data);
        void addVertex(Vertex<T, W> * _vertex);
        void addEdge(const T & origin_data, const T & destination_data, const W & _weight = 1);
        void addEdge(Vertex<T, W> * _origin, Vertex<T, W> * _destination, const W & _weight = 1);
        void addEdge(Edge<T, W> * _edge);
        Vertex<T, W> * getStart() { return start; }
        void setStart(Vertex<T, W> * _start) { start = _start; }
        void setStart(const T & _data);
        void printBreathFirst();
        void printDepthFirst();
        void clearVisits();
        std::list<Vertex<T, W> *> * findPath(Vertex<T, W> * origin, Vertex<T, W> * destination);
        std::list<Vertex<T, W> *> * findPath(const T & origin, const T & destination);
        void initializeDijkstra(std::list<InfoNode<T, W> *> * dijkstra, Vertex<T, W> * origin);
        InfoNode<T, W> * getCheapest(std::list<InfoNode<T, W> *> * dijkstra);
        void printPath(std::list<Vertex<T, W> *> * path);
};

template <class T, class W>
Graph<T, W>::~Graph()
{
    //vertices.~list();
}

template <class T, class W>
void Graph<T, W>::addVertex(const T & _data)
{
    Vertex<T, W> * new_vertex = new Vertex<T, W>(_data);
    this->addVertex(new_vertex);
}

template <class T, class W>
void Graph<T, W>::addVertex(Vertex<T, W> * _vertex)
{
    std::cout << "ADDING VERTEX: " << *_vertex << std::endl;
    vertices.push_back(_vertex);
}

template <class T, class W>
void Graph<T, W>::addEdge(const T & origin_data, const T & destination_data, const W & _weight)
{
    Vertex<T, W> * _origin = nullptr;
    Vertex<T, W> * _destination = nullptr;
    // Look for the vertices that contain the data specified

    for (auto iterator = std::begin(vertices); iterator!=std::end(vertices); ++iterator)
    {
        if ((*iterator)->getData() == origin_data)
            _origin = *iterator;
        if ((*iterator)->getData() == destination_data)
            _destination = *iterator;
    }
    // Call the other methods in this class to add edges
    addEdge(_origin, _destination, _weight);
}

template <class T, class W>
void Graph<T, W>::addEdge(Vertex<T, W> * _origin, Vertex<T, W> * _destination, const W & _weight)
{
    if (_origin != nullptr && _destination != nullptr)
    {
        Edge<T, W> * new_edge = new Edge<T, W>(_origin, _destination, _weight);
        addEdge(new_edge);
    }
}

template <class T, class W>
void Graph<T, W>::addEdge(Edge<T, W> * _edge)
{
    if (_edge != nullptr)
    {
        // Insert the edge to the list in the graph
        edges.push_back(_edge);
        // Add the edge to the list in the origin vertex
        _edge->getOrigin()->addEdge(_edge);
    }
}

template <class T, class W>
void Graph<T, W>::setStart(const T & _data)
{
    for (auto iterator = std::begin(vertices); iterator!=std::end(vertices); ++iterator)
    {
        if ((*iterator)->getData() == _data)
        {
            std::cout << "SETTING START TO: " << **iterator << std::endl;
            setStart(*iterator);
        }
        return;
    }
}

template <class T, class W>
void Graph<T, W>::printBreathFirst()
{
    if (start == nullptr)
        return;

    Vertex<T, W> * vertex = nullptr;
    Vertex<T, W> * neighbour = nullptr;
    std::list<Edge<T, W> *> * edge_list = nullptr;
    std::queue<Vertex<T, W> *> print_queue;

    std::cout << "Breadth First Traversal:" << std::endl;
    // Make sure all vertices are marked as not visited
    clearVisits();
    // Add the initial node to the queue
    print_queue.push(start);
    while(!print_queue.empty())
    {
        // Get the element at the front of the queue
        vertex = print_queue.front();
        // Remove the element from the queue
        print_queue.pop();
        std::cout << vertex->getData() << " -> ";
        // Mark the iterator as visited
        vertex->visit();
        // Get the list of edges
        edge_list = vertex->getEdges();
        for (auto iterator = std::begin(*edge_list); iterator!=std::end(*edge_list); ++iterator)
        {
            // Get the destination of the edge stored in the list
            neighbour = (*iterator)->getDestination();
            // If the neighbour has not been visited, add it to the print_queue
            if (!neighbour->isVisited())
            {
                print_queue.push(neighbour);
            }
        }
    }
    std::cout << std::endl;
}

template <class T, class W>
void Graph<T, W>::printDepthFirst()
{
    if (start == nullptr)
        return;

    Vertex<T, W> * vertex = nullptr;
    Vertex<T, W> * neighbour = nullptr;
    std::list<Edge<T, W> *> * edge_list = nullptr;
    std::stack<Vertex<T, W> *> print_stack;

    std::cout << "Breadth First Traversal:" << std::endl;
    // Make sure all vertices are marked as not visited
    clearVisits();
    // Add the initial node to the stack
    print_stack.push(start);
    while(!print_stack.empty())
    {
        // Get the element at the top of the stack
        vertex = print_stack.top();
        // Remove the element from the stack
        print_stack.pop();
        std::cout << vertex->getData() << " -> ";
        // Mark the iterator as visited
        vertex->visit();
        // Get the list of edges
        edge_list = vertex->getEdges();
        for (auto iterator = std::begin(*edge_list); iterator!=std::end(*edge_list); ++iterator)
        {
            // Get the destination of the edge stored in the list
            neighbour = (*iterator)->getDestination();
            // If the neighbour has not been visited, add it to the print_stack
            if (!neighbour->isVisited())
            {
                print_stack.push(neighbour);
            }
        }
    }
    std::cout << std::endl;
}

template <class T, class W>
void Graph<T, W>::clearVisits()
{
    for (auto iterator = std::begin(vertices); iterator!=std::end(vertices); ++iterator)
    {
        (*iterator)->unvisit();
    }
}

template <class T, class W>
std::list<Vertex<T, W> *> * Graph<T, W>::findPath(const T & origin_data, const T & destination_data)
{
    Vertex<T, W> * _origin = nullptr;
    Vertex<T, W> * _destination = nullptr;

    // Look for the vertices that contain the data specified
    for (auto iterator = std::begin(vertices); iterator!=std::end(vertices); ++iterator)
    {
        if ((*iterator)->getData() == origin_data)
            _origin = *iterator;
        if ((*iterator)->getData() == destination_data)
            _destination = *iterator;
    }
    // Find the path from the origin vertex to the destination vertex
    return findPath(_origin, _destination);
}

template <class T, class W>
std::list<Vertex<T, W> *> * Graph<T, W>::findPath(Vertex<T, W> * origin, Vertex<T, W> * destination)
{
    std::list<Vertex<T, W> *> * path = new std::list<Vertex<T, W> *>;
    std::list<InfoNode<T, W> *> dijkstra;
    InfoNode<T, W> * info_node = nullptr;
    InfoNode<T, W> * current_info_node = nullptr;
    Vertex<T, W> * current = nullptr;
    Vertex<T, W> * neighbour = nullptr;
    std::list<Edge<T, W> *> * edge_list = nullptr;

    initializeDijkstra(&dijkstra, origin);

    current_info_node = dijkstra.front();
    current = current_info_node->getVertex();
    // Loop until the destination is reached
    while (current_info_node != nullptr and current != destination)
    {
        // Get the list of edges
        edge_list = current->getEdges();
        // Get the node with the first edge
        for (auto edge_iterator = std::begin(*edge_list); edge_iterator!=std::end(*edge_list); ++edge_iterator)
        {
            // Get the destination of the edge stored in the node
            neighbour = (*edge_iterator)->getDestination();
            // Update the cost for each neighbour
            for (auto dijkstra_iterator = std::begin(dijkstra); dijkstra_iterator!=std::end(dijkstra); ++dijkstra_iterator)
            {
                info_node = *dijkstra_iterator;
                if (info_node->getVertex() == neighbour)
                {
                    // Add cost of the current node and the edge weight to the neighbour
                    W new_cost = current_info_node->getCost() + (*edge_iterator)->getWeight();
                    // If the new cost is lower, than the previous, or if no cost has been determined yet
                    if (info_node->getCost() == -1 or new_cost < info_node->getCost())
                    {
                        info_node->setCost(new_cost);
                        info_node->setPrevious(current);
                    }
                }
            }
        }
        // Continue by checking the next cheapest item in the dijkstra list
        current_info_node = getCheapest(&dijkstra);
        current_info_node->visit();
        current = current_info_node->getVertex();
        //std::cout << "Current is now: " << current->getData() << std::endl;
    }

    // Recover the path from origin to destination
    while(current_info_node->getPrevious() != nullptr)
    {
        path->push_back(current_info_node->getVertex());
        for (auto dijkstra_iterator = std::begin(dijkstra); dijkstra_iterator!=std::end(dijkstra); ++dijkstra_iterator)
        {
            // Locate the vertex that is marked as previous in the info node
            if ((*dijkstra_iterator)->getVertex() == current_info_node->getPrevious())
            {
                current_info_node = *dijkstra_iterator;
                break;
            }
        }
    }
    // Insert the origin node
    path->push_back(current_info_node->getVertex());

    return path;
}

template <class T, class W>
void Graph<T, W>::printPath(std::list<Vertex<T, W> *> * path)
{
    std::cout << "THE PATH:\n" << std::endl;
    for (auto iterator = std::begin(*path); iterator != std::end(*path); ++iterator)
    {
        std::cout << **iterator << " -> ";
    }
    std::cout << std::endl;
}

template <class T, class W>
void Graph<T, W>::initializeDijkstra(std::list<InfoNode<T, W> *> * dijkstra, Vertex<T, W> * origin)
{
    InfoNode<T, W> * info_node = nullptr;
    Vertex<T, W> * current = nullptr;

    // Fill the dijkstra list with info nodes
    for (auto iterator = std::begin(vertices); iterator!=std::end(vertices); ++iterator)
    {
        current = *iterator;
        info_node = new InfoNode<T, W> (current);
        if (current == origin)
        {
            info_node->setCost(0);
        }
        dijkstra->push_back(info_node);
    }
}

template <class T, class W>
InfoNode<T, W> * Graph<T, W>::getCheapest(std::list<InfoNode<T, W> *> * dijkstra)
{
    InfoNode<T, W> * info_node = nullptr;
    InfoNode<T, W> * lowest_vertex = nullptr;
    W lowest_cost = 99999999;

    for (auto iterator = std::begin(*dijkstra); iterator!=std::end(*dijkstra); ++iterator)
    {
        info_node = *iterator;
        if (info_node->getCost() != -1 and info_node->getCost() < lowest_cost and !info_node->isVisited())
        {
            lowest_cost = info_node->getCost();
            lowest_vertex = info_node;
        }
    }
    return lowest_vertex; 
}
