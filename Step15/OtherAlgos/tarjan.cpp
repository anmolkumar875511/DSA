#include<iostream>
#include<vector>
#include<stack>
using namespace std;


class Solution {
private:
    int timer = 0;

    void dfs(int u,
             vector<int>& disc,
             vector<int>& low,
             vector<bool>& inStack,
             stack<int>& st,
             vector<vector<int>>& graph,
             vector<vector<int>>& SCCs) {

        disc[u] = low[u] = timer++;
        st.push(u);
        inStack[u] = true;

        for(int v : graph[u]) {
            if(disc[v] == -1) {
                dfs(v, disc, low, inStack, st, graph, SCCs);
                low[u] = min(low[u], low[v]);
            }
            else if(inStack[v]) {
                low[u] = min(low[u], disc[v]);
            }
        }

        if(disc[u] == low[u]) {
            vector<int> component;
            while(true) {
                int node = st.top();
                st.pop();
                inStack[node] = false;
                component.push_back(node);
                if(node == u) break;
            }

            SCCs.push_back(component);
        }
    }

public:
    vector<vector<int>> tarjan(int V, vector<vector<int>>& edges) {
        vector<vector<int>> graph(V);
        for(auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
        }

        vector<int> disc(V, -1);
        vector<int> low(V, -1);
        vector<bool> inStack(V, false);
        stack<int> st;
        vector<vector<int>> SCCs;
        for(int i = 0; i < V; i++) {
            if(disc[i] == -1) {
                dfs(i, disc, low, inStack, st, graph, SCCs);
            }
        }

        return SCCs;
    }
};


int main() {
    Solution sol;
    int V = 5;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {3, 4}};
    vector<vector<int>> SCCs = sol.tarjan(V, edges);
    for(auto &SCC : SCCs) {
        for(int u : SCC) {
            cout << u << " ";
        }
        cout << endl;
    }
    return 0;
}
