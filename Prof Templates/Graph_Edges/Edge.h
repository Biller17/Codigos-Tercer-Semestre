#pragma once

template <class T, class W>
class Vertex;

template <class T, class W>
class Edge {
    private:
        W weight;
        Vertex<T, W> * origin;
        Vertex<T, W> * destination;
    public:
        Edge() : origin(nullptr), destination(nullptr), weight(1) {}
        Edge(Vertex<T, W> * _origin, Vertex<T, W> * _destination, const W & _weight) :
            origin(_origin), destination(_destination), weight(_weight) {}
        void setWeight(const W & _weight) { weight = _weight; }
        Vertex<T, W> * getOrigin() { return origin; }
        Vertex<T, W> * getDestination() { return destination; }
        W getWeight() { return weight; }
};
