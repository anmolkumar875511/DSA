#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n);
        for(vector<int>& flight : flights) {
            graph[flight[0]].emplace_back(flight[1], flight[2]);
        }

        queue<tuple<int, int, int>> q;
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        q.emplace(0, src, 0);
        while(!q.empty()) {
            auto [stop, u, d] = q.front();
            q.pop();
            if(stop > k) {
                break;
            }
            for(auto [v, w] : graph[u]) {
                if(d + w < dist[v]) {
                    dist[v] = d + w;
                    q.emplace(stop + 1, v, dist[v]);
                }
            }
        }
        return (dist[dst] == 1e9 ? -1 : dist[dst]);
    }
};


int main() {
    Solution sol;
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    cout << sol.findCheapestPrice(4, flights, 0, 3, 1);
    return 0;
}