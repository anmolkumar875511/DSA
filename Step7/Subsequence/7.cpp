#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void helper(vector<vector<int>>& a, vector<int>& v, int i, vector<int> candidates, int target) {
        if(target == 0) {
            a.push_back(v);
            return;
        }
        for (int idx = i; idx < candidates.size(); idx++) {
            if (idx > i && candidates[idx] == candidates[idx - 1]) continue;

            if (candidates[i] > target) break;

            v.push_back(candidates[idx]);
            helper(a, v, idx + 1, candidates, target - candidates[idx]);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> v;
        vector<vector<int>> a;
        helper(a, v, 0, candidates, target);
        return a;
    }
};


int main() {
    Solution sol;
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> result = sol.combinationSum2(candidates, target);
    
    for (const auto& combination : result) {
        cout << "[ ";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}