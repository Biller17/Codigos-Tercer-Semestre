#include <iostream>
#include "Graph.h"

int main()
{
    Graph<std::string, float> graph;
    Vertex<std::string, float> * vertex;
    std::string cities[] = {"Mexico", "Guadalajara", "Puebla", "Queretaro", "Cuernavaca", "Veracruz", "Villahermosa", "Acapulco"};
    int num_cities = sizeof cities / sizeof cities[0];
    std::list<Vertex<std::string, float> *> * path = nullptr;

    for (int i=0; i<num_cities; i++)
    {
        vertex = new Vertex<std::string, float>(cities[i]);
        graph.addVertex(vertex);
    }

    graph.setStart("Mexico");
    graph.addEdge("Mexico", "Puebla", 2.8);
    graph.addEdge("Puebla", "Veracruz", 8.2);
    graph.addEdge("Veracruz", "Villahermosa", 5.2);
    graph.addEdge("Guadalajara", "Queretaro", 0.7);
    graph.addEdge("Mexico", "Cuernavaca", 6.8);
    graph.addEdge("Cuernavaca", "Acapulco", 6.8);
    graph.addEdge("Mexico", "Guadalajara", 3.2);
    graph.addEdge("Queretaro", "Mexico", 2.1);
    graph.addEdge("Queretaro", "Acapulco", 5.1);

    graph.printBreathFirst();
    graph.printDepthFirst();

    path = graph.findPath("Mexico", "Villahermosa");
    std::cout << "Resulting path:" << std::endl << "\t";
    for (auto iterator = std::begin(*path); iterator != std::end(*path); ++iterator)
    {
        std::cout << (**iterator).getData() << " -> ";
    }
    std::cout << std::endl;

    return 0;
}
