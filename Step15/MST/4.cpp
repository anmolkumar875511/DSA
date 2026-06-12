#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> graph(V);
        for(vector<int>& edge : edges) {
            graph[edge[0]].emplace_back(edge[1], edge[2]);
            graph[edge[1]].emplace_back(edge[0], edge[2]);
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> vis(V, false);
        pq.emplace(0, 0);
        int sum = 0;
        
        while(!pq.empty()) {
            auto [w, u] = pq.top();
            pq.pop();
            
            if(vis[u]) continue;
            vis[u] = true;
            sum += w;
            
            for(auto [v, W] : graph[u]) {
                if(vis[v]) continue;
                pq.emplace(W, v);
            }
        }
        return sum;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> edges = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
    cout << sol.spanningTree(4, edges);
    return 0;
}