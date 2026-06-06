#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
private:
    bool dfs(int node, stack<int>& st, vector<bool>& vis, vector<bool>& pathVis, vector<vector<int>>& graph) {
        vis[node] = true;
        pathVis[node] = true;
        for(int neigh : graph[node]) {
            if(!vis[neigh]) {
                if(dfs(neigh, st, vis, pathVis, graph)) return true;
            }
            else if(pathVis[neigh]) return true;
        }
        pathVis[node] = false;
        st.push(node);
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(vector<int>& prerequisite : prerequisites) {
            graph[prerequisite[1]].push_back(prerequisite[0]);
        }

        vector<bool> vis(numCourses, false), pathVis(numCourses, false);
        stack<int> st;
        vector<int> ans;
        for(int i = 0; i < numCourses; i++) {
            if(vis[i]) continue;
            if(dfs(i, st, vis, pathVis, graph)) return ans;
        }

        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};

int main() {
    Solution sol;
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    vector<int> ans = sol.findOrder(numCourses, prerequisites);
    for(int num : ans) cout << num << " ";
    return 0;
}