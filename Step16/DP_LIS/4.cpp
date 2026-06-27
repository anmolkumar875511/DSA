#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1), hash(n, 0);
        int max_len = 1, last_idx = 0;
        for(int i = 0; i < n; i++) {
            hash[i] = i;
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0 && dp[i] < 1 + dp[j]) {
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }
            if(max_len < dp[i]) {
                max_len = dp[i];
                last_idx = i;
            }
        }
        vector<int> ans(max_len);
        int i = 0;
        while(last_idx != hash[last_idx]) {
            ans[i] = nums[last_idx];
            last_idx = hash[last_idx];
            i++;
        }
        ans[i] = nums[last_idx];
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<int> ans = sol.largestDivisibleSubset(nums);
    for(int num : ans) cout << num << " ";
    return 0;
}