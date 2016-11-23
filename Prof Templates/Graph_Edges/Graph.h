#pragma once

#include <iostream>
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "Vertex.h"
#include "InfoNode.h"

template <class T, class W>
class Graph {
    private:
        LinkedList<Vertex<T, W> *> vertices;
        LinkedList<Edge<T, W> *> edges;
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
        LinkedList<Vertex<T, W> *> * findPath(Vertex<T, W> * origin, Vertex<T, W> * destination);
        LinkedList<Vertex<T, W> *> * findPath(const T & origin, const T & destination);
        void initializeDijkstra(LinkedList<InfoNode<T, W> *> * dijkstra, Node<Vertex<T, W> *> * node, Vertex<T, W> * origin);
        InfoNode<T, W> * getCheapest(LinkedList<InfoNode<T, W> *> * dijkstra);
};

template <class T, class W>
Graph<T, W>::~Graph()
{
    vertices.~LinkedList();
    vertices = nullptr;
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
    Node<Vertex<T, W> *> * node = new Node<Vertex<T, W> *>(_vertex);
    vertices.insertTail(node);
}

template <class T, class W>
void Graph<T, W>::addEdge(const T & origin_data, const T & destination_data, const W & _weight)
{
    Vertex<T, W> * _origin = nullptr;
    Vertex<T, W> * _destination = nullptr;
    Vertex<T, W> * current = nullptr;
    Node<Vertex<T, W> *> * node = vertices.getHead();
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
        edges.insertTail(_edge);
        // Add the edge to the list in the origin vertex
        _edge->getOrigin()->addEdge(_edge);
    }
}

template <class T, class W>
void Graph<T, W>::setStart(const T & _data)
{
    Vertex<T, W> * current = nullptr;
    Node<Vertex<T, W> *> * node = vertices.getHead();
    // Look for the vertices that contain the data specified
    while (node != nullptr)
    {
        current = node->getData();
        if (current->getData() == _data)
        {
            setStart(current);
            return;
        }
        node = node->getNext();
    }
}

template <class T, class W>
void Graph<T, W>::printBreathFirst()
{
    if (start == nullptr)
        return;

    Vertex<T, W> * current = nullptr;
    Vertex<T, W> * neighbour = nullptr;
    Node<Edge<T, W> *> * node = nullptr;
    LinkedList<Edge<T, W> *> * edge_list = nullptr;
    Queue<Vertex<T, W> *> queue;

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
        // Get the list of edges
        edge_list = current->getEdges();
        // Get the node with the first edge
        node = edge_list->getHead();
        while(node != nullptr)
        {
            // Get the destination of the edge stored in the node
            neighbour = node->getData()->getDestination();
            // If the neighbour has not been visited, add it to the queue
            if (!neighbour->isVisited())
            {
                queue.insert(neighbour);
            }
            // Get next neighbour
            node = node->getNext();
        }
    }
    std::cout << std::endl;
}

template <class T, class W>
void Graph<T, W>::printDepthFirst()
{
    if (start == nullptr)
        return;

    Vertex<T, W> * current = nullptr;
    Vertex<T, W> * neighbour = nullptr;
    Node<Edge<T, W> *> * node = nullptr;
    LinkedList<Edge<T, W> *> * edge_list = nullptr;
    Stack<Vertex<T, W> *> stack;

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
        // Get the list of edges
        edge_list = current->getEdges();
        // Get the node with the first edge
        node = edge_list->getHead();
        while(node != nullptr)
        {
            // Get the destination of the edge stored in the node
            neighbour = node->getData()->getDestination();
            // If the neighbour has not been visited, add it to the stack
            if (!neighbour->isVisited())
            {
                stack.push(neighbour);
            }
            // Get next neighbour
            node = node->getNext();
        }
    }
    std::cout << std::endl;
}

template <class T, class W>
void Graph<T, W>::clearVisits()
{
    // Set all vertices as not visited
    Node<Vertex<T, W> *> * node = vertices.getHead();
    Vertex<T, W> * current;

    while(node != nullptr)
    {
        current = node->getData();
        current->unvisit();
        node = node->getNext();
    }
}

template <class T, class W>
LinkedList<Vertex<T, W> *> * Graph<T, W>::findPath(const T & origin_data, const T & destination_data)
{
    Vertex<T, W> * _origin = nullptr;
    Vertex<T, W> * _destination = nullptr;
    Vertex<T, W> * current = nullptr;
    Node<Vertex<T, W> *> * node = vertices.getHead();
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
    // Find the path from the origin vertex to the destination vertex
    return findPath(_origin, _destination);
}

template <class T, class W>
LinkedList<Vertex<T, W> *> * Graph<T, W>::findPath(Vertex<T, W> * origin, Vertex<T, W> * destination)
{
    LinkedList<Vertex<T, W> *> * path = new LinkedList<Vertex<T, W> *>;
    LinkedList<InfoNode<T, W> *> dijkstra;
    Node<InfoNode<T, W> *> * dijkstra_node = nullptr;
    InfoNode<T, W> * info_node = nullptr;
    InfoNode<T, W> * current_info_node = nullptr;
    Node<Edge<T, W> *> * edge_node = nullptr;
    Vertex<T, W> * current = nullptr;
    Vertex<T, W> * neighbour = nullptr;
    LinkedList<Edge<T, W> *> * edge_list = nullptr;

    initializeDijkstra(&dijkstra, vertices.getHead(), origin);

    current_info_node = dijkstra.getHead()->getData();
    current = current_info_node->getVertex();
    // Loop until the destination is reached
    while (current_info_node != nullptr and current != destination)
    {
         // Get the list of edges
        edge_list = current->getEdges();
        // Get the node with the first edge
        edge_node = edge_list->getHead();
        while(edge_node != nullptr)
        {
            // Get the destination of the edge stored in the node
            neighbour = edge_node->getData()->getDestination();
            // Update the cost for each neighbour
            dijkstra_node = dijkstra.getHead();
            while (dijkstra_node != nullptr)
            {
                info_node = dijkstra_node->getData();
                if (info_node->getVertex() == neighbour)
                {
                    // Add cost of the current node and the edge weight to the neighbour
                    W new_cost = current_info_node->getCost() + edge_node->getData()->getWeight();
                    // If the new cost is lower, than the previous, or if no cost has been determined yet
                    if (info_node->getCost() == -1 or new_cost < info_node->getCost())
                    {
                        info_node->setCost(new_cost);
                        info_node->setPrevious(current);
                    }
                }
                dijkstra_node = dijkstra_node->getNext();
            }
            // Get next neighbour
            edge_node = edge_node->getNext();
        }
        // Continue by checking the next cheapest item in the dijkstra list
        current_info_node = getCheapest(&dijkstra);
        current_info_node->visit();
        current = current_info_node->getVertex();
    }

    // Recover the path from origin to destination
    while(current_info_node->getPrevious() != nullptr)
    {
        // Insert the vertex in to the path list
        path->insertTail(current_info_node->getVertex());
        // Look in the list of info nodes for the previous vertex
        dijkstra_node = dijkstra.getHead();
        while (dijkstra_node != nullptr)
        {
            info_node = dijkstra_node->getData();
            // Get the vertex that is marked as previous in this info node
            if (info_node->getVertex() == current_info_node->getPrevious())
            {
                current_info_node = info_node;
                break;
            }
            dijkstra_node = dijkstra_node->getNext();
        }
    }
    // Insert the origin vertex in the list
    path->insertTail(current_info_node->getVertex());

    return path;
}

template <class T, class W>
void Graph<T, W>::initializeDijkstra(LinkedList<InfoNode<T, W> *> * dijkstra, Node<Vertex<T, W> *> * node, Vertex<T, W> * origin)
{
    InfoNode<T, W> * info_node = nullptr;
    InfoNode<T, W> * current_info_node = nullptr;
    Vertex<T, W> * current = nullptr;

    // Fill the dijkstra list with info nodes
    while(node != nullptr)
    {
        current = node->getData();
        info_node = new InfoNode<T, W> (current);
        if (current == origin)
        {
            info_node->setCost(0);
            current_info_node = info_node;
        }
        dijkstra->insertTail(info_node);
        node = node->getNext();
    }
}

template <class T, class W>
InfoNode<T, W> * Graph<T, W>::getCheapest(LinkedList<InfoNode<T, W> *> * dijkstra)
{
    InfoNode<T, W> * info_node = nullptr;
    InfoNode<T, W> * lowest_vertex = nullptr;
    Node<InfoNode<T, W> *> * list_node;
    W lowest_cost = 99999999;

    list_node = dijkstra->getHead();
    while(list_node != nullptr)
    {
        info_node = list_node->getData();
        //std::cout << "Comparing with: " << *info_node << std::endl;
        if (info_node->getCost() != -1 and info_node->getCost() < lowest_cost and !info_node->isVisited())
        {
            lowest_cost = info_node->getCost();
            lowest_vertex = info_node;
        }
        list_node = list_node->getNext();
    }
    return lowest_vertex; 
}
