#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    void dfsRecursive(int v, vector<bool>& visited, const vector<vector<int>>& adj) {
        visited[v] = true;
        for (int w : adj[v])
            if (!visited[w])
                dfsRecursive(w, visited, adj);
    }

    void dfsIterative(int src, int V, const vector<vector<int>>& adj) {
        vector<bool> visited(V, false);
        stack<int> stk;
        stk.push(src);
        while (!stk.empty()) {
            int v = stk.top(); stk.pop();
            if (visited[v]) continue;
            visited[v] = true;
            for (int w : adj[v])
                if (!visited[w]) stk.push(w);
        }
    }
};


int main() {
    Solution sol;
    vector<vector<int>> adj = {{1, 2}, {3}, {3}, {}};
    vector<bool> visited(4, false);
    sol.dfsRecursive(0, visited, adj);
    sol.dfsIterative(0, 4, adj);
    return 0;
}