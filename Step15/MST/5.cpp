#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    int findParent(int u, vector<int>& parent) {
        if(u == parent[u]) {
            return u;
        }
        return parent[u] = findParent(parent[u], parent);
    }

    void unionByRank(int u, int v, vector<int>& parent, vector<int>& rank) {
        int pu = findParent(u, parent);
        int pv = findParent(v, parent);
        if(pu == pv) {
            return;
        }
        if(rank[pu] > rank[pv]) {
            parent[pv] = pu;
        }
        else if(rank[pu] < rank[pv]) {
            parent[pu] = pv;
        }
        else {
            parent[pv] = pu;
            rank[pu]++; 
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n > connections.size() + 1) {
            return -1;
        }
        vector<int> rank(n, 0), parent(n);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for(vector<int>& connection : connections) {
            int u = connection[0];
            int v = connection[1];
            if(findParent(u, parent) == findParent(v, parent)) {
                continue;
            }
            unionByRank(u, v, parent, rank);
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += (findParent(i, parent) == i);
        }
        return ans - 1;
    }
};


int main() {
    Solution sol;
    int n = 4;
    vector<vector<int>> connections = {{0,1},{0,2},{1,2}};
    cout << sol.makeConnected(n, connections) << endl; // Output: 1
    return 0;
}