#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    int counter (vector<int> & nums, int i, int sum) {
        if(sum == 0) return 1;
        if(i == nums.size() || sum < 0) return 0;
        return counter(nums, i+1, sum) + counter(nums, i+1, sum-nums[i]);
    }
    int countSubsequenceWithTargetSum(vector<int>& nums, int k){
    	return counter(nums, 0, k);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 5;
    cout << sol.countSubsequenceWithTargetSum(nums, k) << endl; // Output: 3
    return 0;
}