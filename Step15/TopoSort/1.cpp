#include<iostream>
#include<vector>
#include<stack>
using namespace std;


class Solution {
private:
    void dfs(int node, stack<int>& st, vector<bool>& vis, vector<vector<int>>& graph) {
        vis[node] = true;
        for(int neigh : graph[node]) {
            if(vis[neigh]) continue;
            dfs(neigh, st, vis, graph);
        }
        st.push(node);
    }
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> graph(V);
        for(vector<int> edge : edges) {
            graph[edge[0]].push_back(edge[1]);
        }
        
        vector<bool> vis(V, false);
        stack<int> st;
        for(int i = 0; i < V; i++) {
            if(vis[i]) continue;
            dfs(i, st, vis, graph);
        }
        
        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};


int main() {
    Solution sol;
    int V = 6;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {4, 5}};
    vector<int> ans = sol.topoSort(V, edges);
    for(int num : ans) cout << num << " ";
    return 0;
}