#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
private:
    void dfs1(int u, vector<bool>& vis, stack<int>& st, vector<vector<int>>& graph) {
        vis[u] = true;

        for(int v : graph[u]) {
            if(!vis[v]) {
                dfs1(v, vis, st, graph);
            }
        }
        st.push(u);
    }

    void dfs2(int u, vector<bool>& vis, vector<vector<int>>& rev_graph, vector<int>& component) {
        vis[u] = true;
        component.push_back(u);

        for(int v : rev_graph[u]) {
            if(!vis[v]) {
                dfs2(v, vis, rev_graph, component);
            }
        }
    }

public:
    vector<vector<int>> kosaraju(int V, vector<vector<int>>& edges) {
        vector<vector<int>> graph(V);
        for(auto &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
        }

        stack<int> st;
        vector<bool> vis(V, false);
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs1(i, vis, st, graph);
            }
        }

        vector<vector<int>> rev_graph(V);
        for(auto &edge : edges) {
            rev_graph[edge[1]].push_back(edge[0]);
        }

        vector<vector<int>> SCCs;
        fill(vis.begin(), vis.end(), false);
        while(!st.empty()) {
            int u = st.top();
            st.pop();

            if(!vis[u]) {
                vector<int> component;
                dfs2(u, vis, rev_graph, component);
                SCCs.push_back(component);
            }
        }

        return SCCs;
    }
};


int main() {
    Solution sol;
    int V = 5;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {3, 4}};
    vector<vector<int>> SCCs = sol.kosaraju(V, edges);
    for(auto &SCC : SCCs) {
        for(int u : SCC) {
            cout << u << " ";
        }
        cout << endl;
    }
    return 0;
}