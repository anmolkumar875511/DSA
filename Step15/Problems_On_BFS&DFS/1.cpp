#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
private:
    void bfs(int src, vector<bool>& visited, vector<vector<int>>& isConnected) {
        queue<int> q;
        visited[src] = true;
        q.push(src);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int v = 0; v < isConnected.size(); v++) {
                if(!visited[v] && isConnected[u][v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt = 0;
        int n = isConnected.size();
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                bfs(i, visited, isConnected);
                cnt++;
            }
        }
        return cnt;
    }
};



int main() {
    Solution sol;
    vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    cout << sol.findCircleNum(isConnected) << endl; // Output: 2
    return 0;
}