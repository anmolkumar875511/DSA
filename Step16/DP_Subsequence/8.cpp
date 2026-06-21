#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int Sum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > Sum) return 0;
        if ((Sum + target) & 1) return 0;
        int k = (Sum + target) / 2;
        int n = nums.size();
        
        vector<int> prev(k + 1, 0), curr(k + 1, 0);
        prev[0] = 1;
        if (nums[0] <= k)
            prev[nums[0]]++;
        for (int i = 1; i < n; i++) {
            for (int sum = 0; sum <= k; sum++) {
                int notTake = prev[sum];
                int take = 0;
                if (nums[i] <= sum)
                    take = prev[sum - nums[i]];
                curr[sum] = take + notTake;
            }
            prev = curr;
        }

        return prev[k];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;
    cout << sol.findTargetSumWays(nums, target) << endl;
    return 0;
}