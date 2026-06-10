#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// does not works with negative weights
class UndirectedGraph {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>> graph(V);
        for(vector<int>& edge : edges) {
            graph[edge[0]].emplace_back(edge[1], edge[2]);
            graph[edge[1]].emplace_back(edge[0], edge[2]);
        }
        
        vector<int> dist(V, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, src);
        dist[src] = 0;
        
        while(!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            for(auto [v, D] : graph[u]) {
                if(dist[v] > dist[u] + D) {
                    dist[v] = dist[u] + D;
                    pq.emplace(dist[u] + D, v);
                }
            }
        }
        
        return dist;
    }
};

// works for negative wights, but does not works for negative cycles
// but do extra iterations
class DirectedGraph {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>> graph(V);
        for(vector<int>& edge : edges) {
            graph[edge[0]].emplace_back(edge[1], edge[2]);
        }
        
        vector<int> dist(V, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, src);
        dist[src] = 0;
        
        while(!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            for(auto [v, D] : graph[u]) {
                if(dist[v] > dist[u] + D) {
                    dist[v] = dist[u] + D;
                    pq.emplace(dist[u] + D, v);
                }
            }
        }
        
        return dist;
    }
};

// does works for negative wights
class DirectedGraph_ {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>> graph(V);
        for(vector<int>& edge : edges) {
            graph[edge[0]].emplace_back(edge[1], edge[2]);
        }
        
        vector<int> dist(V, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace(0, src);
        dist[src] = 0;
        
        while(!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if(d > dist[u]) continue;
            for(auto [v, D] : graph[u]) {
                if(dist[v] > dist[u] + D) {
                    dist[v] = dist[u] + D;
                    pq.emplace(dist[u] + D, v);
                }
            }
        }
        
        return dist;
    }
};