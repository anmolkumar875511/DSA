#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> bfs(int src, int V,
                    const vector<vector<int>>& adj) {
        vector<int> dist(V, -1);
        queue<int> q;
        dist[src] = 0;
        q.push(src);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int w : adj[v]) {
                if (dist[w] == -1) {
                    dist[w] = dist[v] + 1;
                    q.push(w);
                }
            }
        }
        return dist;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> adj = {{1, 2}, {3}, {3}, {}};
    vector<int> dist = sol.bfs(0, 4, adj);
    for (int d : dist) cout << d << " ";
    return 0;
}