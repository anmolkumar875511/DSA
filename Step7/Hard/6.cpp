#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    bool is_possible(int u, int c, vector<int>& colors, vector<vector<int>>& graph) {
        for(int v : graph[u]) {
            if(colors[v] == c) {
                return false;
            }
        }
        return true;
    }
    bool f(int u, int m, vector<int>& colors, vector<vector<int>>& graph) {
        if(u == colors.size()) {
            return true;
        }
        for(int c = 0; c < m; c++) {
            if(is_possible(u, c, colors, graph)) {
                colors[u] = c;
                if(f(u + 1, m, colors, graph) == true) {
                    return true;
                }
                colors[u] = -1;
            }
        }
        return false;
    }
public:
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        vector<vector<int>> graph(v);
        for(vector<int>& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<int> colors(v, -1);
        return f(0, m, colors, graph);
    }
};


int main() {
    Solution sol;
    int v = 3;
    vector<vector<int>> edges = {{0,1},{1,2},{2,0}};
    int m = 3;
    cout << (sol.graphColoring(v, edges, m) ? "true" : "false") << endl;
    return 0;
}