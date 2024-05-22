#
#    ID: 8240
#    Mail: matank214@gmail.com
#

Graph
    Description: class that represents a graph.

    Data members:
        * vector<vector<int>> graph - represents the graph as a 2D matrix.

        * size_t size - number of vertices.

        * bool isDirected - represents if the graph is directed(true) or not directed(false).

        * int weihgt - represents if the graph is no-weighted/non-negative-weighted/negative-weighted.
        

    Methods:
        * Graph() - empty constructor.

        * ~Graph() - empty destructor.

        * void loadGraph(vector<vector<int>>, bool isdirec= true) - load the given graph in the data member and if the graph is directed.

        Throw error if the graph is not squre matrix or if the graph is not directed and the edge (i,j) != (j,i) for all i,j that are vertices.

        * void printGraph() - print each row in the matrix of this.

        * size_t getSize() - return the data number size.

        * int getEdge(size_t i, size_t j) - return the edge (i,j), 0 if the edge doesn't exit.

        * bool getIsDirected() - return the data member isDirected.

        * int getEdges() - return how many edges exits in the graph.

        * int getWeight() - return which weight is the graph.

        * Graph operator=(const Graph &other) - operator that's take other graph and puts it in this.

        * Graph operator+(const Graph &other) - operator that returns a graph "ans" that is the sum between this and other, meaning that ans[i,j] = this[i,j] + other[i,j] for all i != j and if i = j then ans[i,j] = 0. if the graphs doesn't have the same amount of vertices then throw exception.

        * Graph &operator+=(const Graph &other) - operator that add Graph other to Graph this, meaning that this[i,j] = this[i,j] + other[i,j] for all i != j and if i = j then ans[i,j] = 0. if the graphs doesn't have the same amount of vertices then throw exception.

        Graph operator+() const - plus unary, return the same graph(this).

        Graph operator-() - unary substraction, return a Graph ans that ans[i.j] = -this[i,j].

        Graph operator-(const Graph &other) - operator that returns a graph "ans" that is the substruct between this and other, meaning that ans[i,j] = this[i,j] - other[i,j] for all i != j and if i = j then ans[i,j] = 0. if the graphs doesn't have the same amount of vertices then throw exception.

        Graph &operator-=(const Graph &other) - operator that substruct Graph other to Graph this, meaning that this[i,j] = this[i,j] - other[i,j] for all i != j and if i = j then ans[i,j] = 0. if the graphs doesn't have the same amount of vertices then throw exception.

        Graph &operator++() - add plus 1 to the graph and return it. for all this[i,j] i != j will add plus 1, else this[i,j] stays the same. if this[i,j] = 0 then it will not add plus one and stay the same.

        Graph operator++(int) - return a copy of the graph and add plus 1 to the original graph. for all this[i,j] i != j will add plus 1, else this[i,j] stays the same. if this[i,j] = 0 then it will not add plus one and stay the same.

        Graph &operator--() - sub 1 from the graph and return it. for all this[i,j] i != j will sub 1, else this[i,j] stays the same. if this[i,j] = 0 then it will not sub by 1 and stay the same.

        Graph operator--(int) - return a copy of the graph and sub 1 from the original graph. for all this[i,j] i != j will sub 1, else this[i,j] stays the same. if this[i,j] = 0 then it will not sub one and stay the same.

        Graph operator*(int num) - return a Graph 'ans" that is the multiply between the graph and a number, meaning ans[i,j] = this[i,j] * num.
        Graph operator*=(int num) - operator that multiply Graph this to number num, meaning that this[i,j] = this[i,j]*num for all i != j and if i = j then ans[i,j] = 0.
        Graph operator*(const Graph &other) - operator that return a Graph "ans" that is the multiply between the Matrix "this" and Matrix "other", meaning that for all i != j ans[i,j] = this[i,k] * other[k,j] for all k between 1 to number of vertices, if i = j then ans[i,j] = 0. throw exception if the graphs doesn't have the same amount of vertices.

        Graph &operator*=(const Graph &other) - operator that return a  multiply between the Matrix "this" and Matrix "other", meaning that for all i != j this[i,j] = this[i,k] * other[k,j] for all k between 1 to number of vertices, if i = j then this[i,j] = 0. throw exception if the graphs doesn't have the same amount of vertices.

        friend std::ostream& operator<<(std::ostream &os, const Graph &g) - return an osstream that represent the graph, the garph will represent as a print of his rows.

        bool operator==(const Graph &other) - return true if this[i,j] = other[i,j] or if !(this < other) && !(this > other). 
        bool operator!=(const Graph &other) - return if !(this = other).
        bool operator>(const Graph &other) const - return true if Graph this contains Graph other, meaning this[i,j] = other[i,j] for all i,j that are vertices in other, else return true if the amount of edges in this is bigger than other, else return true if this has more vertices than other, else return false.

        bool operator<(const Graph &other) const - return true if Graph other contains Graph this, meaning this[i,j] = other[i,j] for all i,j that are vertices in this, else return true if the amount of edges in other is bigger than this, else return true if other has more vertices than this, else return false.
        bool operator>=(const Graph &other) - return true if this > other or this = other.
        bool operator<=(const Graph &other) - return true if this < other or this = other.


Algorithms
    Description: class that represents algorithms on graph.

    Data members: None

    Methods:
        * static void isConnected(const ariel::Graph &graph) - if the graph is directed, do BFS on the graph and check for each vertex if all the vertices are reachable(distance != INF), else do BFS for all the vertices and check if all the vertices are reachable.

        * static void shortestPath(const ariel::Graph &graph, int start, int end, int algo = negative_weight) - if the graph is negative weighted run Bellman Ford, if it's weighted then run dijkstra, if the graph is not weighted then run BFS. return the weight of the shortest path, INF if it's not reachable or the graph contains negative cycle.

        * static void isContainsCycle(const ariel::Graph &graph) - run a similar DFS on the graph until we met a vertex twice(aka GRAY), if so take that vertex and start going backward(aka parent[v]) until we reach a vetex twice and prints the path. If we don't meet vertex twice then print that there isn't a cycle in the graph.

        * static void isBipartite(const ariel::Graph &graph) - will run a BFS and color the vertex in blue and red so that each parent will color its child in different color of his color, if two neighbors are in the same color prints that there isn't a bipartite , else will prints a 2 sets that represent a Bipartite.

        * static void negativeCycle(const ariel::Graph &graph) - will add extra vertex and run a Bellman-Ford, if we can relax an edge again (after the Bellman-ford)then take one of the vertices and run for his parents until we get the same vertex twice and print that path, else return that there isn't negativeCycle.