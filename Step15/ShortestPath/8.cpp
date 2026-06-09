#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for(vector<int>& time : times) {
            graph[time[0]].emplace_back(time[1], time[2]);
        }

        vector<int> dist(n + 1, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[k] = 0;
        pq.emplace(0, k);
        while(!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            for(auto [v, D] : graph[u]) {
                if(dist[u] + D < dist[v]) {
                    dist[v] = dist[u] + D;
                    pq.emplace(dist[v], v);
                }
            }
        }
        int ans = 0;
        dist[0] = 0;
        for(int d : dist) {
            ans = max(ans, d);
            if(d == 1e9) return -1;
        }
        return ans;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    cout << sol.networkDelayTime(times, 4, 2);
    return 0;
}