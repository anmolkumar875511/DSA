#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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

        return ans.size() == numCourses;
    }
};

int main() {
    Solution sol;
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};
    cout << (sol.canFinish(numCourses, prerequisites) ? "true" : "false") << endl;
    return 0;
}