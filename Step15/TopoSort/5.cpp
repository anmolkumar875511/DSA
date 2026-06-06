#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(auto& prerequisite : prerequisites) {
            graph[prerequisite[1]].push_back(prerequisite[0]);
        }

        vector<int> inDegree(numCourses, 0);
        for(int i = 0; i < numCourses; i++) {
            for(int v : graph[i]) {
                inDegree[v]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for(int v : graph[u]) {
                inDegree[v]--;
                if(inDegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        if(ans.size() != numCourses) {
            return {};
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