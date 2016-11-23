#include <iostream>
#include "Graph.h"

int main()
{
    Graph<int> graph;
    Vertex<int> * vertex_1;
    Vertex<int> * vertex_2;

    vertex_1 = new Vertex<int>(11);
    graph.addVertex(vertex_1);
    vertex_2 = new Vertex<int>(22);
    graph.addVertex(vertex_2);

    graph.addEdge(11, 22);
    //graph.addEdge(vertex_1, vertex_2);

    vertex_2 = new Vertex<int>(33);
    graph.addVertex(vertex_2);
    graph.addEdge(11, 33);

    vertex_2 = new Vertex<int>(44);
    graph.addVertex(vertex_2);
    graph.addEdge(33, 44);

    vertex_2 = new Vertex<int>(55);
    graph.addVertex(vertex_2);
    graph.addEdge(44, 55);

    graph.addEdge(44, 11);

    graph.setStart(vertex_1);
    graph.printBreathFirst();
    graph.printDepthFirst();
}
