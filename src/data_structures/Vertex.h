#ifndef DA_PROJECT_2_VERTEX_H
#define DA_PROJECT_2_VERTEX_H

#include "Edge.h"
#include "MutablePriorityQueue.h"
#include "../Haversine.h"
#include "../Coordinate.h"
#include <string>
#include <vector>
#include <iostream>

class Edge;

class Vertex {
public:
    explicit Vertex(int in);

    bool operator<(Vertex & vertex) const;

    [[nodiscard]] int getInfo() const;

    [[nodiscard]] Coordinate getCoord() const;

    [[nodiscard]] double getDist() const;

    [[nodiscard]] std::vector<Edge *> getAdj() const;

    [[nodiscard]] bool isVisited() const;

    [[nodiscard]] bool isProcessing() const;

    [[nodiscard]] unsigned int getIndegree() const;

    [[nodiscard]] Edge *getPath() const;

    void setCoord(Coordinate coordinate);

    void setDist(double dist);

    [[nodiscard]] std::vector<Edge *> getIncoming() const;

    void setVisited(bool visited);

    void setProcesssing(bool processing);

    void setIndegree(unsigned int indegree);

    void setPath(Edge *path);

    Edge * addEdge(Vertex *dest, double dist);

    Edge* findEdge(Vertex* dest);

    bool removeEdge(int in);

    void removeOutgoingEdges();

    friend class MutablePriorityQueue<Vertex>;

    void setDegree(unsigned int c);

    [[nodiscard]] unsigned int getDegree() const;

protected:
    int info;

    Coordinate coord {0,0};

    double dist = 0;

    std::vector<Edge *> adj;

    bool visited = false;

    bool processing = false;

    unsigned int indegree{};

    Edge *path = nullptr;

    std::vector<Edge *> incoming;

    void deleteEdge(Edge *edge);

    int queueIndex = 0; // required by MutablePriorityQueue

    unsigned int degree = 0;
};

#endif //DA_PROJECT_2_VERTEX_H
