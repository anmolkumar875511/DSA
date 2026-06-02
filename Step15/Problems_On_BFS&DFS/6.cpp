#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    bool dfs(int u, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis) {
        vis[u] = 1;
        pathVis[u] = 1;

        for (int v : adj[u]) {
            if (!vis[v]) {
                if (dfs(v, adj, vis, pathVis))
                    return true;
            }
            else if (pathVis[v]) {
                return true;
            }
        }

        pathVis[u] = 0;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, pathVis))
                    return false;
            }
        }

        return true;
    }
};


int main() {
    Solution sol;
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};
    cout << (sol.canFinish(numCourses, prerequisites) ? "true" : "false") << endl;
    return 0;
}