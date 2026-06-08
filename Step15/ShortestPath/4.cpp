#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        vector<vector<pair<int, int>>> graph(V);
        for(vector<int>& edge : edges) {
            graph[edge[0]].emplace_back(edge[1], edge[2]);
            graph[edge[1]].emplace_back(edge[0], edge[2]);
        }
        
        vector<int> dist(V, 1e9);
        set<pair<int, int>> st;
        st.insert({0, src});
        dist[src] = 0;
        
        while(!st.empty()) {
            auto it = *(st.begin());
            auto [d, u] = it;
            st.erase(it);
            for(auto [v, D] : graph[u]) {
                if(dist[v] > dist[u] + D) {
                    if(dist[v] != 1e9) {
                        st.erase({dist[v], v});
                    }
                    dist[v] = dist[u] + D;
                    st.insert({dist[u] + D, v});
                }
            }
        }
        
        return dist;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> edges = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
    vector<int> dist = sol.dijkstra(4, edges, 0);
    for(int d : dist) {
        cout << d << " ";
    }
    return 0;
}