#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void helper(vector<vector<int>>& ans, vector<int>& v, vector<int>& candidates, int i, int target) {
        if(target == 0) {
            ans.push_back(v);
            return;
        }
        if(i == candidates.size() || target < 0) {
            return;
        }
        v.push_back(candidates[i]);
        helper(ans, v, candidates, i, target-candidates[i]);
        v.pop_back();
        helper(ans, v, candidates, i+1, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        vector<vector<int>> ans;
        helper(ans, v, candidates, 0, target);
        return ans;
    }
};


int main() {
    Solution sol;
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> result = sol.combinationSum(candidates, target);
    
    for (const auto& combination : result) {
        cout << "[ ";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}