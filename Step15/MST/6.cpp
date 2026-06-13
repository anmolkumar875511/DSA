#include<iostream>
#include<vector>
#include<unordered_set>
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
    int removeStones(vector<vector<int>>& stones) {
        int rows = 0, cols = 0;
        for(vector<int>& stone : stones) {
            rows = max(rows, stone[0]);
            cols = max(cols, stone[1]);
        }

        DisjointSet DS(rows + cols + 1);
        unordered_set<int> s;
        for(vector<int>& stone : stones) {
            int u = stone[0];
            int v = stone[1] + rows + 1;
            DS.unionBySize(u, v);
            s.insert(u);
            s.insert(v);
        }
        int cnt = 0;
        for(int u : s) {
            cnt += (DS.findParent(u) == u);
        }
        return stones.size() - cnt;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> stones = {{0,0},{0,1},{1,0},{1,2},{2,1},{2,2}};
    cout << sol.removeStones(stones) << endl; // Output: 5
    return 0;
}