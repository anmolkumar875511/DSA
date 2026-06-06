#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    bool dfs(int src, vector<vector<int>>& graph, vector<bool>& vis, vector<bool>& pathVis) {
        vis[src] = true;
        pathVis[src] = true;
        
        for(int neigh : graph[src]) {
            if(!vis[neigh]) {
                if(dfs(neigh, graph, vis, pathVis)) return true;
            }
            else if(pathVis[neigh]) return true;
        }
        
        pathVis[src] = false;
        return false;
    }
public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> graph(V);
        for(auto& edge : edges) {
            graph[edge[1]].push_back(edge[0]);
        }
        
        vector<bool> vis(V, false), pathVis(V, false);
        for(int i = 0; i < V; i++) {
            if(vis[i]) continue;
            if(dfs(i, graph, vis, pathVis)) return true;
        }
        return false;
    }
};

int main() {
    Solution sol;
    int V = 3;
    vector<vector<int>> edges = {{0,1},{1,2},{2,0}};
    cout << (sol.isCyclic(V, edges) ? "true" : "false") << endl;
    return 0;
}