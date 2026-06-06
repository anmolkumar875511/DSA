#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int> q;
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i = 0; i < n; i++) {
            if(color[i] != -1) continue;
            q.push(i);
            color[i] = 0;
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                for(int v : graph[u]) {
                    if(color[v] == color[u]) return false;
                    if(color[v] != -1) continue;
                    color[v] = !color[u];
                    q.push(v);
                }
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> graph = {{1,3},{0,2},{1,3},{0,2}};
    cout << (sol.isBipartite(graph) ? "true" : "false") << endl;
    return 0;
}