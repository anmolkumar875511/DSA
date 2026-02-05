#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    bool finder(vector<int>& nums, int idx, int sum) {
        if(idx == nums.size()) {
            return sum == 0;
        }
        return finder(nums, idx+1, sum) | finder(nums, idx+1, sum-nums[idx]);
    }
    bool checkSubsequenceSum(vector<int>& nums, int k) {
         return finder(nums, 0, k);
    }
};


int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 5;
    cout << sol.checkSubsequenceSum(nums, k) << endl; // Output: 1 (true)
    return 0;
}