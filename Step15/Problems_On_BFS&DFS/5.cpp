#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
private:
    vector<vector<int>> edges_to_adjList(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        return adj;
    }

public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        auto adj = edges_to_adjList(V, edges);

        vector<bool> visited(V, false);

        for (int start = 0; start < V; start++) {
            if (visited[start]) continue;

            queue<pair<int,int>> q;
            q.push({start, -1});
            visited[start] = true;

            while (!q.empty()) {
                auto [u, par] = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push({v, u});
                    }
                    else if (v != par) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};


int main() {
    Solution sol;
    int V = 3;
    vector<vector<int>> edges = {{0,1},{1,2},{2,0}};
    cout << (sol.isCycle(V, edges) ? "true" : "false") << endl;
    return 0;
}