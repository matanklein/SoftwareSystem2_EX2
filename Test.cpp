#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"
#include <sstream>

using namespace std;

TEST_CASE("Test graph addition")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 + g2;
    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    ariel::Graph expectedGraph3;
    expectedGraph3.loadGraph(expectedGraph);
    CHECK(g3 == expectedGraph3);

    stringstream ans;
    ans << g3;
    CHECK(ans.str() == "[0, 2, 1]\n[2, 0, 3]\n[1, 3, 0]\n");

    g3 += g1;
    vector<vector<int>> expectedGraph2 = {
        {0, 3, 1},
        {3, 0, 4},
        {1, 4, 0}};
    ariel::Graph expectedGraph4;
    expectedGraph4.loadGraph(expectedGraph2);
    CHECK(g3 == expectedGraph4);

    g1 = +g1;
    ans << g1;
    CHECK(ans.str() == "[0, 1, 0]\n[1, 0, 1]\n[0, 1, 0]\n");

    graph = {
        {1}};
    ariel::Graph g4;
    g4.loadGraph(graph);
    CHECK_THROWS(g1 + g4);

    vector<vector<int>> expectedGraph7 = {
        {0, 2, 2},
        {2, 0, 3},
        {2, 3, 0}};
    ariel::Graph expectedGraph5;
    expectedGraph5.loadGraph(expectedGraph7);
    CHECK((g2++) == expectedGraph5);

    vector<vector<int>> Graph6 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    ariel::Graph g6;
    g6.loadGraph(Graph6);
    ariel::Graph g7 = g6++;
    stringstream ans2;
    ans2 << g7;
    CHECK(ans2.str() == "[0, 2, 2]\n[2, 0, 3]\n[2, 3, 0]\n");

    g7 = ++g6;
    stringstream ans3;
    ans3 << g7;
    CHECK(ans3.str() == "[0, 2, 2]\n[2, 0, 3]\n[2, 3, 0]\n");

    vector<vector<int>> allGraph1 = {
        {-1, -1, -1},
        {-1, -1, -1},
        {-1, -1,-1}};
    ariel::Graph g8;
    g8.loadGraph(allGraph1);
    g8 = g8++;
    stringstream ans4;
    ans4 << g8;
    CHECK(ans4.str() == "[0, 0, 0]\n[0, 0, 0]\n[0, 0, 0]\n");
}

TEST_CASE("Test graph subtraction")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 - g2;
    vector<vector<int>> expectedGraph = {
        {0, 0, -1},
        {0, 0, -1},
        {-1, -1, 0}};

    stringstream ans;
    ans << g3;
    CHECK(ans.str() == "[0, 0, -1]\n[0, 0, -1]\n[-1, -1, 0]\n");

    g3 -= g1;
    CHECK(g3.printGraph() == "[0, -1, -1]\n[-1, 0, -2]\n[-1, -2, 0]");

    g1 = -g1;
    CHECK(g1.printGraph() == "[0, -1, 0]\n[-1, 0, -1]\n[0, -1, 0]");

    graph = {
        {1}};
    ariel::Graph g4;
    g4.loadGraph(graph);
    CHECK_THROWS(g1 - g4);

    vector<vector<int>> expectedGraph2 = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}};
    ariel::Graph expectedGraph5;
    expectedGraph5.loadGraph(expectedGraph2);
    vector<vector<int>> gOnePlus1 = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}};
    ariel::Graph gOnePlus;
    gOnePlus.loadGraph(gOnePlus1);
    CHECK(gOnePlus-- == expectedGraph5);

    vector<vector<int>> Graph6 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    ariel::Graph g6;
    g6.loadGraph(Graph6);
    ariel::Graph g7 = g6--;
    stringstream ans2;
    ans2 << g7;
    CHECK(ans2.str() == "[0, 0, 0]\n[0, 0, 1]\n[0, 1, 0]\n");

}
TEST_CASE("Test graph multiplication")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g4 = g1 * g2;
    CHECK(g4.printGraph() == "[0, 0, 2]\n[1, 0, 1]\n[1, 0, 0]");
    vector <vector<int>> Graph1 = {
        {0, 0},
        {1, 0}};
    ariel::Graph g5;
    g5.loadGraph(Graph1);
    CHECK_THROWS(g1 * g5);
}

TEST_CASE("Test graph regular multiply"){
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g3 = g1 * 2;
    CHECK(g3.printGraph() == "[0, 2, 0]\n[2, 0, 2]\n[0, 2, 0]");
    ariel::Graph g5 = g2 * 0;
    CHECK(g5.printGraph() == "[0, 0, 0]\n[0, 0, 0]\n[0, 0, 0]");
    g5 = g2 * 1;
    CHECK(g5.printGraph() == "[0, 1, 1]\n[1, 0, 2]\n[1, 2, 0]");
    g5 = g2 * -1;
    CHECK(g5.printGraph() == "[0, -1, -1]\n[-1, 0, -2]\n[-1, -2, 0]");
}

TEST_CASE("Test graph operators"){
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    vector<vector<int>> Graph3 = {
        {0, 1},
        {1, 0}};
    vector<vector<int>> Graph5 = {
        {0, 2},
        {1, 0}};
    vector<vector<int>> Graph6 = {
        {0, 0, 0},
        {1, 0, 1},
        {0, 0, 0}};
    vector<vector<int>> Graph7 = {
        {0, 1, 0},
        {0, 0, 0},
        {0, 1, 0}};
    ariel::Graph g4;
    g4.loadGraph(Graph3);
    ariel::Graph g5;
    g5.loadGraph(Graph5);
    ariel::Graph g6;
    g6.loadGraph(Graph6);
    ariel::Graph g7;
    g7.loadGraph(Graph7);
    g2.loadGraph(weightedGraph);
    CHECK(g1 == g1);

    ariel::Graph g3 = g1;
    CHECK(g1 == g3);

    CHECK(g1 != g2);

    CHECK(g1 < g2); // g2 has more edges than g1

    CHECK(g4 < g2); // g2 contains g4

    CHECK(g5 < g6); // g6 has more verteices than g5

    CHECK(g6 == g7); // g6 not bigger than g7 and g7 not bigger than g6
    
    CHECK(g1 <= g2);
    CHECK(g1 <= g3);

    CHECK(g2 > g1);
    CHECK(g2 >= g1);
}