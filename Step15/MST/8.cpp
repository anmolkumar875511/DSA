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

class Solution{
public:
vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators){
        int cmpSize = 0;
        vector<int> ans;
        DisjointSet DS(n * m);
        vector<bool> vis(n * m, false);
        vector<int> DIR = {0, -1, 0, 1, 0};
        for(vector<int>& point : operators) {
            int r = point[0];
            int c = point[1];
            int idx = r * m + c;
            if(vis[idx]) {
                ans.push_back(cmpSize);
                continue;
            }
            vis[idx] = true;
            cmpSize++;
            for(int i = 0; i < 4; i++) {
                int nr = r + DIR[i];
                int nc = c + DIR[i + 1];
                if(nr < 0 || nr == n || nc < 0 || nc == m) {
                    continue;
                }
                int nxt_idx = nr * m + nc;
                if(!vis[nxt_idx]) {
                    continue;
                }
                if(DS.findParent(idx) != DS.findParent(nxt_idx)) {
                    DS.unionByRank(idx, nxt_idx);
                    cmpSize--;
                }
            }
            ans.push_back(cmpSize);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int n = 3, m = 3;
    vector<vector<int>> operators = {{0, 0}, {0, 1}, {1, 2}, {2, 1}, {2, 2}, {1, 1}};
    vector<int> ans = sol.numOfIslands(n, m, operators);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
