#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> graph(n);
        for(vector<int>& edge : edges) {
            graph[edge[0]].emplace_back(edge[1], edge[2]);
            graph[edge[1]].emplace_back(edge[0], edge[2]);
        }
        int minC = n;
        int city = 0;
        for(int i = 0; i < n; i++) {
            vector<int> dist(n, 1e9);
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            dist[i] = 0;
            pq.emplace(0, i);
            while(!pq.empty()) {
                auto [d, u] = pq.top();
                pq.pop();
                if(dist[u] < d) {
                    continue;
                }
                for(auto [v, D] : graph[u]) {
                    if(dist[v] > d + D) {
                        dist[v] = d + D;
                        pq.emplace(dist[v], v);
                    }
                }
            }
            int cnt = 0;
            for(int j = 0; j < n; j++) {
                if(dist[j] <= distanceThreshold && i != j) {
                    cnt++;
                }
            }
            if(minC >= cnt) {
                minC = cnt;
                city = i;
            }
        }
        return city;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> edges = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
    cout << sol.findTheCity(4, edges, 4);
    return 0;
}
