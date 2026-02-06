#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void helper(vector<int>& nums, vector<int>& v, vector<vector<int>>& a, int i) {
        a.push_back(v);
        for(int j = i; j < nums.size(); j++) {
            if(j > i && nums[j-1] == nums[j]) continue;
            v.push_back(nums[j]);
            helper(nums, v, a, j+1);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> v;
        vector<vector<int>> a;
        helper(nums, v, a, 0);
        return a;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> result = sol.subsetsWithDup(nums);
    
    for (const auto& subset : result) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}