#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> graph(n);
        for(vector<int>& road : roads) {
            graph[road[0]].emplace_back(road[1], road[2]);
            graph[road[1]].emplace_back(road[0], road[2]);
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> dist(n, 4e18);
        vector<long long> ways(n, 0);
        pq.emplace(0, 0);
        dist[0] = 0;
        ways[0] = 1;

        while(!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u]) {
                continue;
            }
            for(auto [v, D] : graph[u]) {
                if(dist[v] == d + D) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
                else if(dist[v] > d + D) {
                    dist[v] = d + D;
                    ways[v] = ways[u];
                    pq.emplace(dist[v], v);
                }
            }
        }
        return ways[n - 1] % MOD;
    }
};


int main() {
    Solution sol;
    int n = 3;
    vector<vector<int>> roads = {{0,1,3},{1,2,1},{1,3,4},{2,3,1}};
    cout << sol.countPaths(n, roads) << endl;
    return 0;
}