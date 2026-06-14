#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, rank, size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1);
        size.resize(n + 1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
            rank[i] = 0;
            size[i] = 1;
        }
    }
    
    int findParent(int node) {
        if(node == parent[node]) {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }
    
    void unionByRank(int u, int v) {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if(ulp_u == ulp_v) {
            return;
        }
        if(rank[ulp_u] > rank[ulp_v]) {
            parent[ulp_v] = ulp_u;
        }
        else if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if(ulp_u == ulp_v) {
            return;
        }
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet DS(n * n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    continue;
                }
                if(j + 1 < n && grid[i][j + 1] == 1) {
                    DS.unionBySize(i * n + j, i * n + (j + 1));
                }
                if(i + 1 < n && grid[i + 1][j] == 1) {
                    DS.unionBySize(i * n + j, (i + 1) * n + j);
                }
            }
        }

        int ans = 0;
        vector<int> DIR = {0, -1, 0, 1, 0};
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    int p = DS.findParent(i * n + j);
                    ans = max(ans, DS.size[p]);
                    continue;
                }
                int total_size = 1;
                unordered_set<int> vis;
                for(int k = 0; k < 4; k++) {
                    int ni = i + DIR[k];
                    int nj = j + DIR[k + 1];
                    if(ni < 0 || ni == n || nj < 0 || nj == n || grid[ni][nj] == 0) {
                        continue;
                    }
                    int nxt = ni * n + nj;
                    int p_nxt = DS.findParent(nxt);
                    if(vis.find(p_nxt) != vis.end()) {
                        continue;
                    }
                    total_size += DS.size[p_nxt];
                    vis.insert(p_nxt);
                }
                ans = max(ans, total_size);
            }
        }
        return ans;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> grid = {{1, 0}, {0, 1}};
    cout << sol.largestIsland(grid) << endl; // Output: 3
    return 0;
}