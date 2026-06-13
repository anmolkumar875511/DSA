#include<iostream>
#include<vector>
#include<unordered_map>
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet DS(n);
        unordered_map<string, int> mapMailNode;
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                if(mapMailNode.find(accounts[i][j]) == mapMailNode.end()) {
                    mapMailNode[accounts[i][j]] = i;
                }
                else {
                    DS.unionBySize(i, mapMailNode[accounts[i][j]]);
                }
            }
        }
        vector<vector<string>> mails(n);
        for(auto [mail, u] : mapMailNode) {
            int pu = DS.findParent(u);
            mails[pu].emplace_back(mail);
        }

        vector<vector<string>> ans;
        for(int i = 0; i < n; i++) {
            if(mails[i].size() == 0) {
                continue;
            }
            sort(mails[i].begin(), mails[i].end());
            vector<string> temp = {accounts[i][0]};
            for(string mail : mails[i]) {
                temp.emplace_back(mail);
            }
            ans.emplace_back(temp);
        }
        return ans;
    }
};


int main() {
    Solution sol;
    vector<vector<string>> accounts = {{"John", "a@b.com", "c@d.com"}, {"John", "a@b.com", "b@c.com"}, {"John", "n@n.com"}, {"Mary", "a@b.com"}};
    vector<vector<string>> ans = sol.accountsMerge(accounts);
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}