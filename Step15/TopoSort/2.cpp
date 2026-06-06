#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> graph(V);
        vector<int> inDegree(V, 0);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            inDegree[v]++;
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);
            for (int v : graph[u]) {
                inDegree[v]--;

                if (inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        return topo;
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
