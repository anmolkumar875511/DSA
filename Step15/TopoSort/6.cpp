#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> outDegree(graph.size(), 0);
        vector<vector<int>> rev_graph(graph.size());
        for(int u = 0; u < graph.size(); u++) {
            outDegree[u] = graph[u].size();
            for(int v : graph[u]) {
                rev_graph[v].push_back(u);
            }
        }

        queue<int> q;
        for(int u = 0; u < graph.size(); u++) {
            if(outDegree[u] == 0) {
                q.emplace(u);
            }
        }

        vector<int> ans;
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            ans.push_back(v);
            for(int u : rev_graph[v]) {
                outDegree[u]--;
                if(outDegree[u] == 0) q.emplace(u);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}};
    vector<int> ans = sol.eventualSafeNodes(graph);
    for(int num : ans) cout << num << " ";
    return 0;
}