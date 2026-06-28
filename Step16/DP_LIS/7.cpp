#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), cnt(n, 1);
        int max_len = 1, ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    if(dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    }
                    else if(dp[i] == dp[j] + 1) {
                        cnt[i] = cnt[i] + cnt[j];
                    }
                }
            }
            if(dp[i] > max_len) {
                max_len = dp[i];
                ans = cnt[i];
            }
            else if(dp[i] == max_len) {
                ans = ans + cnt[i];
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 5, 4, 7};
    int ans = sol.findNumberOfLIS(nums);
    cout << ans << endl;
    return 0;
}