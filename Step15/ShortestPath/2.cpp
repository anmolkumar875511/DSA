#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
private:
    void dfs(int u, stack<int>& st, vector<bool>& vis, vector<vector<pair<int, int>>>& graph) {
        vis[u] = true;
        
        for(auto& [v, d] : graph[u]) {
            if(vis[v]) {
                continue;
            }
            dfs(v, st, vis, graph);
        }
        
        st.push(u);
    }
    
public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> graph(V);
        for(vector<int>& edge : edges) {
            graph[edge[0]].emplace_back(edge[1], edge[2]);
        }
        
        vector<bool> vis(V, false);
        stack<int> st;
        for(int i = 0; i < V; i++) {
            if(vis[i]) {
                continue;
            }
            dfs(i, st, vis, graph);
        }
        
        vector<int> dist(V, 1e9);
        dist[0] = 0;
        
        while(!st.empty()) {
            int u = st.top();
            st.pop();
            if(dist[u] == 1e9) {
                continue;
            }
            for(auto& [v, d] : graph[u]) {
                dist[v] = min(dist[v], dist[u] + d);
            }
        }
        
        for(int i = 0; i < V; i++) {
            if(dist[i] == 1e9) {
                dist[i] = -1;
            }
        }
        
        return dist;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> edges = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
    vector<int> dist = sol.shortestPath(4, 4, edges);
    for(int d : dist) {
        cout << d << " ";
    }
    return 0;
}
