#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    int timer = 1;
    void dfs(int u, int p, vector<int>& low, vector<int>& tin, vector<bool>& vis, vector<vector<int>>& bridges, vector<vector<int>>& graph) {
        vis[u] = true;
        low[u] = tin[u] = timer;
        timer++;
        for(int v : graph[u]) {
            if(v == p) {
                continue;
            }
            if(vis[v]) {
                low[u] = min(low[u], low[v]);
            }
            else {
                dfs(v, u, low, tin, vis, bridges, graph);
                low[u] = min(low[u], low[v]);
                if(low[v] > tin[u]) {
                    bridges.push_back({u, v});
                }
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        for(vector<int>& connection : connections) {
            graph[connection[0]].emplace_back(connection[1]);
            graph[connection[1]].emplace_back(connection[0]);
        }

        vector<vector<int>> bridges;
        vector<bool> vis(n, false);
        vector<int> low(n, 0);
        vector<int> tin(n, 0);
        dfs(0, -1, low, tin,vis, bridges, graph);
        return bridges;
    }
};