#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        vector<vector<int>> graph(V);
        for(vector<int>& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<int> dist(V, -1);
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int v : graph[u]) {
                if(dist[v] != -1) {
                    continue;
                }
                dist[v] = 1 + dist[u];
                q.push(v);
            }
        }
        return dist;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges = {{0,1},{0,2},{1,2},{1,3},{2,3}};
    vector<int> dist = sol.shortestPath(4, edges, 0);
    for(int d : dist) {
        cout << d << " ";
    }
    return 0;
}
