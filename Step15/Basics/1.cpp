#include<iostream>
#include<vector>
using namespace std;
struct Graph {
    int V;
    vector<vector<pair<int,int>>> adj;

    explicit Graph(int v) : V(v), adj(v) {}

    void addEdge(int u, int v, int w = 1, bool directed = true) {
        adj[u].emplace_back(v, w);
        if (!directed) adj[v].emplace_back(u, w);
    }
};
Graph buildSampleGraph() {
    Graph g(7);
    g.addEdge(0, 1, 2); g.addEdge(0, 3, 1);
    g.addEdge(1, 3, 3); g.addEdge(1, 4, 10);
    g.addEdge(2, 0, 4); g.addEdge(2, 5, 5);
    g.addEdge(3, 2, 2); g.addEdge(3, 4, 2);
    g.addEdge(3, 5, 8); g.addEdge(3, 6, 4);
    g.addEdge(4, 6, 6); g.addEdge(6, 5, 1);
    return g;
}