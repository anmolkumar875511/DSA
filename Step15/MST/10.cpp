#include<iostream>
#include<vector>
using namespace std;

class DisjointSet {
private:
    vector<int> parent, rank, size;
public:
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
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int, int>> pos(n * n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                pos[grid[i][j]] = {i, j};
            }
        }
        DisjointSet DS(n * n);
        vector<int> DIR = {0, -1, 0, 1, 0};
        for(int t = 0; t < n * n; t++) {
            auto [i, j] = pos[t];
            for(int k = 0; k < 4; k++) {
                int ni = i + DIR[k];
                int nj = j + DIR[k + 1];
                if(ni < 0 || ni == n || nj < 0 || nj == n || grid[ni][nj] > t) {
                    continue;
                }
                DS.unionBySize(i * n + j, ni * n + nj);
                if(DS.findParent(0) == DS.findParent(n * n - 1)) {
                    return t;
                }
            }
        }
        return 0;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {{0, 2}, {1, 3}};
    cout << sol.swimInWater(grid) << endl; // Output: 3
    return 0;
}