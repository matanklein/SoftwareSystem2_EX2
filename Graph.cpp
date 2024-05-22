/*
    ID: 8240
    Mail: matank214@gmail.com
*/

#include "Graph.hpp"

ariel::Graph::Graph()
{
    this->size = 0;
}

void ariel::Graph::loadGraph(std::vector<std::vector<int>> graph, bool isDirected)
{
    int numRows = graph.size();
    for (size_t i = 0; i < numRows; i++)
    {
        if (graph[i].size() != numRows)
        {
            throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
        }
    }
    if (!isDirected)
    {
        for (size_t i = 0; i < numRows; i++)
        {
            for (size_t j = 0; j < numRows; j++)
            {
                if (graph[i][j] != graph[j][i])
                {
                    throw std::invalid_argument("Invalid graph: The graph is not undirected.");
                }
            }
        }
    }
    bool flag = true;
    this->weihgt = negative_weight;
    this->graph = graph;
    this->size = graph.size();
    this->isDirected = isDirected;
}

int ariel::Graph::getEdges() const
{
    if (this->size == 0)
    {
        return 0;
    }

    int edges = 0;
    for (size_t i = 0; i < this->size; i++)
    {
        for (size_t j = 0; j < this->size; j++)
        {
            if (this->graph[i][j] != 0)
            {
                edges++;
            }
        }
    }
    if (this->isDirected)
    {
        return edges;
    }
    return edges / 2;
}

std::string ariel::Graph::printGraph()
{
    if (size == 0)
    {
        return "Graph is empty.";
    }
    std::string str = "";
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            if (j == 0)
            {
                str = str + "[" + std::to_string(graph[i][j]) + ", ";
            }
            else if (j == size - 1)
            {
                str = str + std::to_string(graph[i][j]) + "]";
            }
            else
                str = str + std::to_string(graph[i][j]) + ", ";
        }
        if (i != size - 1)
        {
            str = str + ", ";
        }
        else
        {
            str = str + "\n";
        }
    }
    return str;
}

ariel::Graph ariel::Graph::operator=(const Graph &other)
{
    this->size = other.size;
    this->isDirected = other.isDirected;
    this->graph = other.graph;
    return *this;
}
ariel::Graph ariel::Graph::operator+(const Graph &other)
{
    if (this->size != other.size)
    {
        throw std::invalid_argument("Invalid operation: The graphs are't the same size.");
    }
    std::vector<std::vector<int>> newGraph(this->size, std::vector<int>(this->size, 0));
    for (size_t i = 0; i < this->size; i++)
    {
        for (size_t j = 0; j < this->size; j++)
        {
            if (i == j)
            {
                newGraph[i][j] = 0;
            }
            else
            {
                newGraph[i][j] = this->graph[i][j] + other.graph[i][j];
            }
        }
    }
    Graph newG;
    newG.loadGraph(newGraph, this->isDirected);
    return newG;
}

ariel::Graph &ariel::Graph::operator+=(const Graph &other)
{
    if (this->size != other.size)
    {
        throw std::invalid_argument("Invalid operation: The graphs are't the same size.");
    }
    for (size_t i = 0; i < this->size; i++)
    {
        for (size_t j = 0; j < this->size; j++)
        {
            if (i == j)
            {
                this->graph[i][j] = 0;
            }
            else
            {
                this->graph[i][j] += other.graph[i][j];
            }
        }
    }
    return *this;
}

ariel::Graph ariel::Graph::operator-()
{
    return *this * -1;
}

ariel::Graph ariel::Graph::operator-(const Graph &other)
{
    if (this->size != other.size)
    {
        throw std::invalid_argument("Invalid operation: The graphs are't the same size.");
    }
    std::vector<std::vector<int>> newGraph(this->size, std::vector<int>(this->size, 0));
    for (size_t i = 0; i < this->size; i++)
    {
        for (size_t j = 0; j < this->size; j++)
        {
            if (i == j)
            {
                newGraph[i][j] = 0;
            }
            else
            {
                newGraph[i][j] = this->graph[i][j] - other.graph[i][j];
            }
        }
    }
    Graph newG;
    newG.loadGraph(newGraph, this->isDirected);
    return newG;
}

ariel::Graph &ariel::Graph::operator-=(const Graph &other)
{
    if (this->size != other.size)
    {
        throw std::invalid_argument("Invalid operation: The graphs are't the same size.");
    }
    for (size_t i = 0; i < this->size; i++)
    {
        for (size_t j = 0; j < this->size; j++)
        {
            if (i == j)
            {
                this->graph[i][j] = 0;
            }
            else
            {
                this->graph[i][j] -= other.graph[i][j];
            }
        }
    }
    return *this;
}

ariel::Graph &ariel::Graph::operator++()
{
    for (size_t i = 0; i < this->size; i++)
    {
        for (size_t j = 0; j < this->size; j++)
        {
            if (this->graph[i][j] != 0)
            {
                this->graph[i][j]++;
            }
        }
    }
    return *this;
}

ariel::Graph ariel::Graph::operator++(int)
{
    Graph temp = *this;
    for (size_t i = 0; i < this->size; i++)
    {
        for (size_t j = 0; j < this->size; j++)
        {
            if (this->graph[i][j] != 0)
            {
                this->graph[i][j]++;
            }
        }
    }
    return temp;
}

ariel::Graph &ariel::Graph::operator--()
{
    for (size_t i = 0; i < this->size; i++)
    {
        for (size_t j = 0; j < this->size; j++)
        {
            if (this->graph[i][j] != 0)
            {
                this->graph[i][j]--;
            }
        }
    }
    return *this;
}

ariel::Graph ariel::Graph::operator--(int)
{
    Graph temp = *this;
    for (size_t i = 0; i < this->size; i++)
    {
        for (size_t j = 0; j < this->size; j++)
        {
            if (this->graph[i][j] != 0)
            {
                this->graph[i][j]--;
            }
        }
    }
    return temp;
}

ariel::Graph ariel::Graph::operator*(int num)
{
    std::vector<std::vector<int>> newGraph(this->size, std::vector<int>(this->size, 0));
    for (size_t i = 0; i < this->size; i++)
    {
        for (size_t j = 0; j < this->size; j++)
        {
            if (i == j)
            {
                newGraph[i][j] = 0;
            }
            else
            {
                newGraph[i][j] = this->graph[i][j] * num;
            }
        }
    }
    Graph newG;
    newG.loadGraph(newGraph);
    return newG;
}

ariel::Graph ariel::Graph::operator*(const Graph &other)
{
    if (this->size != other.size)
    {
        throw std::invalid_argument("Invalid operation: The graphs are't the same size.");
    }
    std::vector<std::vector<int>> newGraph(this->size, std::vector<int>(this->size, 0));
    for (size_t i = 0; i < this->size; i++)
    {
        for (size_t j = 0; j < this->size; j++)
        {
            for (size_t k = 0; k < this->size; k++)
            {
                if (i == j)
                {
                    newGraph[i][j] = 0;
                }
                else
                {
                    newGraph[i][j] += this->graph[i][k] * other.graph[k][j];
                }
            }
        }
    }
    Graph newG;
    newG.loadGraph(newGraph, this->isDirected);
    return newG;
}

ariel::Graph &ariel::Graph::operator*=(const Graph &other)
{
    if (this->size != other.size)
    {
        throw std::invalid_argument("Invalid operation: The graphs are't the same size.");
    }
    std::vector<std::vector<int>> newGraph(this->size, std::vector<int>(this->size, 0));
    for (size_t i = 0; i < this->size; i++)
    {
        for (size_t j = 0; j < this->size; j++)
        {
            for (size_t k = 0; k < this->size; k++)
            {
                if (i == j)
                {
                    newGraph[i][j] = 0;
                }
                else
                {
                    newGraph[i][j] += this->graph[i][k] * other.graph[k][j];
                }
            }
        }
    }
    this->loadGraph(newGraph, this->isDirected);
    return *this;
}
namespace ariel
{
    std::ostream& operator<<(std::ostream &os, const Graph &g)
    {
        if (g.size == 0)
        {
            os << "Graph is empty." << std::endl;
            return os;
        }
        for (size_t i = 0; i < g.size; i++)
        {
            for (size_t j = 0; j < g.size; j++)
            {
                if (j == 0)
                {
                    os << "[" << g.graph[i][j] << ", ";
                }
                else if (j == g.size - 1)
                {
                    os << g.graph[i][j] << "]";
                }
                else
                    os << g.graph[i][j] << ", ";
            }
            if (i != g.size - 1)
            {
                os << ", ";
            }
            else
            {
                os << std::endl;
            }
        }
        return os;
    }
}

bool ariel::Graph::operator==(const Graph &other) const
{
    bool option1 = true;
    if (this->size != other.size)
    {
        option1 = false;
    }
    for (size_t i = 0; i < this->size && option1; i++)
    {
        for (size_t j = 0; j < this->size; j++)
        {
            if (this->graph[i][j] != other.graph[i][j])
            {
                option1 = false;
            }
        }
    }
    if (option1)
    {
        return true;
    }
    bool option2 = !(other < *this) && !(*this < other);
    return option2;
}

bool ariel::Graph::operator!=(const Graph &other)
{
    return !(*this == other);
}

bool ariel::Graph::operator>=(const Graph &other)
{
    return (*this > other) || (*this == other);
}

bool ariel::Graph::operator<=(const Graph &other)
{
    return (*this < other) || (*this == other);
}

bool ariel::Graph::operator>(const Graph &other) const
{
    bool option = true;
    if (this->size >= other.size)
    {
        for (size_t i = 0; i < other.size && option; i++)
        {
            for (size_t j = 0; j < other.size && option; j++)
            {
                if (this->graph[i][j] != other.graph[i][j])
                {
                    option = false;
                }
            }
        }
    }
    if (option)
    {
        return true;
    }
    int thisEdges = this->getEdges();
    int otherEdges = other.getEdges();
    if (!this->isDirected)
    {
        thisEdges *= 2;
    }
    if (!other.isDirected)
    {
        otherEdges *= 2;
    }
    if (thisEdges > otherEdges)
    {
        return true;
    }
    if (thisEdges == otherEdges && this->size > other.size)
    {
        return true;
    }
    return false;
}

bool ariel::Graph::operator<(const Graph &other) const
{
    bool option = true;
    if (this->size <= other.size)
    {
        for (size_t i = 0; i < this->size && option; i++)
        {
            for (size_t j = 0; j < this->size && option; j++)
            {
                if (this->graph[i][j] != other.graph[i][j])
                {
                    option = false;
                }
            }
        }
    }
    if (option)
    {
        return true;
    }
    int thisEdges = this->getEdges();
    int otherEdges = other.getEdges();
    if (!this->isDirected)
    {
        thisEdges *= 2;
    }
    if (!other.isDirected)
    {
        otherEdges *= 2;
    }
    if (thisEdges < otherEdges)
    {
        return true;
    }
    if (thisEdges == otherEdges && this->size < other.size)
    {
        return true;
    }
    return false;
}

ariel::Graph ariel::Graph::operator*=(int num)
{
    for (size_t i = 0; i < this->size; i++)
    {
        for (size_t j = 0; j < this->size; j++)
        {
            if (i == j)
            {
                this->graph[i][j] = 0;
            }
            else
            {
                this->graph[i][j] *= num;
            }
        }
    }
    return *this;
}