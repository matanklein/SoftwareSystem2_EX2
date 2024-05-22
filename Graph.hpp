/*
    ID: 8240
    Mail: matank214@gmail.com
*/

#include <vector>
#include <iostream>
#include <string>

#ifndef GRAPH_H
#define GRAPH_H

#define no_weights 0
#define Nonnegative_weights 1
#define negative_weight 2

namespace ariel
{

    class Graph
    {

    private:
        std::vector<std::vector<int>> graph;
        size_t size;
        bool isDirected;
        int weihgt;

    public:
        Graph();
        ~Graph() {}
        void loadGraph(std::vector<std::vector<int>>, bool isdirec = true);
        std::string printGraph();
        size_t getSize() const
        {
            return size;
        }
        int getEdge(size_t i, size_t j) const
        {
            return graph[i][j];
        }
        bool getIsDirected() const
        {
            return isDirected;
        }
        int getEdges() const;
        int getWeight() const
        {
            return weihgt;
        }

        Graph operator=(const Graph &other);

        Graph operator+(const Graph &other);
        Graph &operator+=(const Graph &other);
        Graph operator+() const
        {
            return *this;
        }

        Graph operator-();
        Graph operator-(const Graph &other);
        Graph &operator-=(const Graph &other);

        Graph &operator++();   // prefix
        Graph operator++(int); // postfix

        Graph &operator--();   // prefix
        Graph operator--(int); // postfix

        Graph operator*(int num);
        Graph operator*=(int num);
        Graph operator*(const Graph &other);
        Graph &operator*=(const Graph &other);

        friend std::ostream& operator<<(std::ostream &os, const Graph &g);

        bool operator==(const Graph &other) const;
        bool operator!=(const Graph &other);
        bool operator>(const Graph &other) const;
        bool operator<(const Graph &other) const;
        bool operator>=(const Graph &other);
        bool operator<=(const Graph &other);
    };

}

#endif