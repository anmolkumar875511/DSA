#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
private:
    int timer = 1;
    void dfs(int u, int parent, vector<bool>& vis, vector<bool>& mark, vector<int>& tin, vector<int>& low, vector<int> adj[]) {
        vis[u] = true;
        tin[u] = low[u] = timer;
        timer++;
        int child = 0;
        for(int v : adj[u]) {
            if(parent == v) {
                continue;
            }
            if(vis[v]) {
                low[u] = min(low[u], tin[v]);
            }
            else {
                child++;
                dfs(v, u, vis, mark, tin, low, adj);
                low[u] = min(low[u], low[v]);
                if(low[v] >= tin[u] && parent != -1) {
                    mark[u] = true;
                }
            }
        }
        if(child > 1 && parent == -1) {
            mark[u] = true;
        }
    }
public:
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        vector<bool> mark(V, false);
        vector<bool> vis(V, false);
        vector<int> low(V, 0);
        vector<int> tin(V, 0);
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs(i, -1, vis, mark, tin , low, adj);
            }
        }
        vector<int> ans;
        for(int i = 0; i < V; i++) {
            if(mark[i]) {
                ans.push_back(i);
            }
        }
        sort(ans.begin(), ans.end());
        if(ans.size()) {
           return ans;
        }
        return {-1};
    }
};


int main() {
    Solution sol;
    int V = 5;
    vector<int> adj[] = {{1}, {0, 2, 4}, {1, 3}, {2}, {1, 4}, {0, 3}};
    vector<int> ans = sol.articulationPoints(V, adj);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}