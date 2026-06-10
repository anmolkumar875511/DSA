#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Solution {
public:
    int minSteps(vector<int>& arr, int start, int end) {
        vector<int> dist(1000, 1e9);
        queue<int> q;
        dist[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (u == end) return dist[u];
            for (int num : arr) {
                int v = (u * num) % 1000;
                if (dist[u] + 1 < dist[v]) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        return -1;
    }
};


int main() {
    
}