#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(n + 2, vector<int> (n + 2, 0));
        for(int i = n; i > 0; i--) {
            for(int j = i; j <= n; j++) {
                int maxE = 0;
                for(int k = i; k <= j; k++) {
                    int reward = (nums[i - 1] * nums[k] * nums[j + 1]) + dp[i][k - 1] + dp[k + 1][j];
                    maxE = max(maxE, reward);
                }
                dp[i][j] = maxE;
            }
        }
        return dp[1][n];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3,1,5,8};
    cout << sol.maxCoins(nums) << endl; // Output: 167
    return 0;
}