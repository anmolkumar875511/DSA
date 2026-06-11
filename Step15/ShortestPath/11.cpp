#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, 1e8);
        dist[src] = 0;

        for(int i = 0; i < V - 1; i++) {
            for(auto &edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];

                if(dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if(dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                return {-1};
            }
        }

        return dist;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges = {{0, 1, 5}, {1, 2, 3}, {2, 3, 3}, {3, 4, 2}, {4, 1, 1}, {0, 4, 1}};
    vector<int> dist = sol.bellmanFord(5, edges, 0);
    for (int d : dist) cout << d << " ";
    return 0;
}