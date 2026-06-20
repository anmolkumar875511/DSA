#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int num : nums) {
            sum += num;
        }
        if(sum & 1) return false;

        sum = sum / 2;
        vector<bool> prev(sum + 1, false), curr(sum + 1, false);
        curr[0] = prev[0] = true;
        if(nums[0] <= sum) {
            prev[nums[0]] = true;
        }

        for(int i = 1; i < n; i++) {
            for(int j = 1; j <= sum; j++) {
                bool not_take = prev[j];
                bool take = false;
                if(nums[i] <= j) {
                    take = prev[j - nums[i]];
                }
                curr[j] = take | not_take;
            }
            prev = curr;
        }
        return prev[sum];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 5, 11, 5};
    cout << (sol.canPartition(nums) ? "true" : "false") << endl;
    return 0;
}