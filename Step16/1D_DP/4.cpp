#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    int rec(int i, vector<int>& nums, vector<int>& dp) {
        if(i < 0) {
            return 0;
        }
        if(dp[i] != -1) return dp[i];
        int pick = nums[i] + rec(i - 2, nums, dp);
        int not_pick = rec(i - 1, nums, dp);
        return dp[i] =  max(pick, not_pick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return rec(n - 1, nums, dp);
    }
};

int main() {
    Solution s;
    int n;
    cin >> n;
    vector<int> nums = {1, 2, 3, 1};
    cout << s.rob(nums) << endl;
    return 0;
}