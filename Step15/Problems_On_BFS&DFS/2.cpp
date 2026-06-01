#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
private:
    vector<vector<int>> edges_to_adjList(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);

        for (auto &e : edges) {
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }

        return adjList;
    }

    pair<int,int> bfs(vector<bool>& vis, int src, vector<vector<int>>& adj) {
        queue<int> q;
        q.push(src);
        vis[src] = true;

        int nodes = 0;
        int edges = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            nodes++;
            edges += adj[u].size();

            for (int v : adj[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }

        return {nodes, edges / 2};
    }

public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        auto adj = edges_to_adjList(n, edges);

        vector<bool> vis(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                auto [nodes, edgesCnt] = bfs(vis, i, adj);

                if (edgesCnt == 1LL * nodes * (nodes - 1) / 2)
                    ans++;
            }
        }

        return ans;
    }
};


int main() {
    Solution sol;
    int n = 6;
    vector<vector<int>> edges = {{0, 3}, {1, 3}, {0, 2}, {2, 4}, {2, 5}, {4, 5}};
    int ans = sol.countCompleteComponents(n, edges);
    cout << ans << endl;
    return 0;
}