#include<iostream>
#include<vector>
using namespace std;

class DisjointSet {
private:
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
            rank[i] = 0;
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
};

class Solution {
 public:
    vector<int> DSU(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        ans.reserve(queries.size());
        DisjointSet DS(n);
        for(vector<int>& query : queries) {
            if(query[0] == 1) {
                DS.unionByRank(query[1], query[2]);
            }
            else {
                int ulp = DS.findParent(query[1]);
                ans.emplace_back(ulp);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int n = 5;
    vector<vector<int>> queries = {{1, 1, 2}, {1, 2, 3}, {2, 1}, {2, 2}, {3, 2}};
    vector<int> ans = sol.DSU(n, queries);
    for(int num : ans) cout << num << " ";
    return 0;
}