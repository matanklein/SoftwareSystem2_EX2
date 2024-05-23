#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"
#include <sstream>

using namespace std;

TEST_CASE("Test graph addition")
{
    ariel::Graph graph1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    graph1.loadGraph(graph);
    ariel::Graph graph2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    graph2.loadGraph(weightedGraph);
    ariel::Graph graph3 = graph1 + graph2;
    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    ariel::Graph expectedGraph3;
    expectedGraph3.loadGraph(expectedGraph);
    CHECK(graph3 == expectedGraph3);

    stringstream ans;
    ans << graph3;
    CHECK(ans.str() == "[0, 2, 1], [2, 0, 3], [1, 3, 0]\n");

    graph3 += graph1;
    vector<vector<int>> expectedGraph2 = {
        {0, 3, 1},
        {3, 0, 4},
        {1, 4, 0}};
    ariel::Graph expectedGraph4;
    expectedGraph4.loadGraph(expectedGraph2);
    CHECK(graph3 == expectedGraph4);

    stringstream ans1;
    graph1 = +graph1;
    ans1 << graph1;
    CHECK(ans1.str() == "[0, 1, 0], [1, 0, 1], [0, 1, 0]\n");

    graph = {
        {1}};
    ariel::Graph graph4;
    graph4.loadGraph(graph);
    CHECK_THROWS(graph1 + graph4);

    vector<vector<int>> expectedGraph7 = {
        {0, 2, 2},
        {2, 0, 3},
        {2, 3, 0}};
    ariel::Graph expectedGraph5;
    expectedGraph5.loadGraph(expectedGraph7);
    CHECK((graph2++) == expectedGraph5);

    vector<vector<int>> Graph6 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    ariel::Graph graph6;
    graph6.loadGraph(Graph6);
    ariel::Graph graph7 = graph6++;
    stringstream ans2;
    ans2 << graph6;
    CHECK(ans2.str() == "[0, 2, 2], [2, 0, 3], [2, 3, 0]\n");
    CHECK(graph7.printGraph() == "[0, 1, 1], [1, 0, 2], [1, 2, 0]\n");

    graph6.loadGraph(Graph6);
    graph7 = ++graph6;
    stringstream ans3;
    ans3 << graph7;
    CHECK(ans3.str() == "[0, 2, 2], [2, 0, 3], [2, 3, 0]\n");

    vector<vector<int>> allGraph1 = {
        {-1, -1, -1},
        {-1, -1, -1},
        {-1, -1,-1}};
    ariel::Graph graph8;
    graph8.loadGraph(allGraph1);
    graph8 = ++graph8;
    stringstream ans4;
    ans4 << graph8;
    CHECK(ans4.str() == "[0, 0, 0], [0, 0, 0], [0, 0, 0]\n");
}

TEST_CASE("Test graph subtraction")
{
    ariel::Graph graph1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    graph1.loadGraph(graph);
    ariel::Graph graph2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    graph2.loadGraph(weightedGraph);
    ariel::Graph graph3 = graph1 - graph2;
    vector<vector<int>> expectedGraph = {
        {0, 0, -1},
        {0, 0, -1},
        {-1, -1, 0}};

    stringstream ans;
    ans << graph3;
    CHECK(ans.str() == "[0, 0, -1], [0, 0, -1], [-1, -1, 0]\n");

    graph3 -= graph1;
    CHECK(graph3.printGraph() == "[0, -1, -1], [-1, 0, -2], [-1, -2, 0]\n");

    graph1 = -graph1;
    CHECK(graph1.printGraph() == "[0, -1, 0], [-1, 0, -1], [0, -1, 0]\n");

    graph = {
        {1}};
    ariel::Graph graph4;
    graph4.loadGraph(graph);
    CHECK_THROWS(graph1 - graph4);

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
    CHECK(--gOnePlus == expectedGraph5);

    vector<vector<int>> Graph6 = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    ariel::Graph graph6;
    graph6.loadGraph(Graph6);
    ariel::Graph graph7 = graph6--;
    stringstream ans2;
    ans2 << graph6;
    CHECK(ans2.str() == "[0, 0, 0], [0, 0, 1], [0, 1, 0]\n");
    CHECK(graph7.printGraph() == "[0, 1, 1], [1, 0, 2], [1, 2, 0]\n");

}
TEST_CASE("Test graph multiplication")
{
    ariel::Graph graph1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    graph1.loadGraph(graph);
    ariel::Graph graph2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    graph2.loadGraph(weightedGraph);
    ariel::Graph graph4 = graph1 * graph2;
    CHECK(graph4.printGraph() == "[0, 0, 2], [1, 0, 1], [1, 0, 0]\n");
    vector <vector<int>> Graph1 = {
        {0, 0},
        {1, 0}};
    ariel::Graph graph5;
    graph5.loadGraph(Graph1);
    CHECK_THROWS(graph1 * graph5);
}

TEST_CASE("Test graph regular multiply"){
    ariel::Graph graph1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    graph1.loadGraph(graph);
    ariel::Graph graph2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    graph2.loadGraph(weightedGraph);
    ariel::Graph graph3 = graph1 * 2;
    CHECK(graph3.printGraph() == "[0, 2, 0], [2, 0, 2], [0, 2, 0]\n");
    ariel::Graph graph5 = graph2 * 0;
    CHECK(graph5.printGraph() == "[0, 0, 0], [0, 0, 0], [0, 0, 0]\n");
    graph5 = graph2 * 1;
    CHECK(graph5.printGraph() == "[0, 1, 1], [1, 0, 2], [1, 2, 0]\n");
    graph5 = graph2 * -1;
    CHECK(graph5.printGraph() == "[0, -1, -1], [-1, 0, -2], [-1, -2, 0]\n");
}

TEST_CASE("Test graph operators"){
    ariel::Graph graph1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    graph1.loadGraph(graph);
    ariel::Graph graph2;
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
    ariel::Graph graph4;
    graph4.loadGraph(Graph3);
    ariel::Graph graph5;
    graph5.loadGraph(Graph5);
    ariel::Graph graph6;
    graph6.loadGraph(Graph6);
    ariel::Graph graph7;
    graph7.loadGraph(Graph7);
    graph2.loadGraph(weightedGraph);
    CHECK(graph1 == graph1);

    ariel::Graph graph3 = graph1;
    CHECK(graph1 == graph3);

    CHECK(graph1 != graph2);

    CHECK(graph1 < graph2); // graph2 has more edges than graph1

    CHECK(graph4 < graph2); // graph2 contains graph4

    CHECK(graph5 < graph6); // graph6 has more verteices than graph5

    CHECK(graph6 == graph7); // graph6 not bigger than graph7 and graph7 not bigger than graph6
    
    CHECK(graph1 <= graph2);
    CHECK(graph1 <= graph3);

    CHECK(graph2 > graph1);
    CHECK(graph2 >= graph1);
}