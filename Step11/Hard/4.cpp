#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<set>
#include<algorithm>
using namespace std;

class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        priority_queue<tuple<int, int, int>> pq;
        set<pair<int, int>> visited;
        
        pq.push({a[0] + b[0], 0, 0});
        visited.insert({0, 0});
        vector<int> ans;
        
        while(k-- && !pq.empty()) {
            auto [sum , i, j] = pq.top();
            pq.pop();
            ans.push_back(sum);
            
            if(i + 1 < a.size() && !visited.count({i + 1, j})) {
                pq.push({a[i + 1] + b[j], i + 1, j});
                visited.insert({i + 1, j});
            }
            if(j + 1 < b.size() && !visited.count({i, j + 1})) {
                pq.push({a[i] + b[ j + 1], i, j + 1});
                visited.insert({i, j + 1});
            }
        }
        return ans;
    }
};


int main() {
    Solution sol;
    vector<int> a = {1,7,11};
    vector<int> b = {2,4,6};
    int k = 3;
    vector<int> ans = sol.topKSumPairs(a, b, k);
    for(int num : ans) cout << num << " ";
    return 0;
}