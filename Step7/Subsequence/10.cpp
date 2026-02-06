#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void helper(vector<int>& nums, vector<int>& v, vector<vector<int>>& a, int i, int sum, int size) {
        if(sum == 0 && v.size() == size) {
            a.push_back(v);
            return;
        }
        if(i == 9 || sum < 0 || v.size() > size) {
            return;
        }
        v.push_back(nums[i]);
        helper(nums, v, a, i+1, sum-nums[i], size);
        v.pop_back();
        helper(nums, v, a, i+1, sum, size);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8 ,9};
        vector<int> v;
        vector<vector<int>> a;
        helper(nums, v, a, 0, n, k);
        return a;
    }
};


int main() {
    Solution sol;
    int k = 3, n = 7;
    vector<vector<int>> result = sol.combinationSum3(k, n);
    
    for (const auto& combination : result) {
        cout << "[ ";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}