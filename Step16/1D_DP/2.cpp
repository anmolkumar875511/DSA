#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n, 0);
        dp[0] = 0;
        if(n > 0) {
            dp[1] = abs(height[0] - height[1]);
        }
        for(int i = 2; i < n; i++) {
            dp[i] = min(dp[i - 1] + abs(height[i] - height[i - 1]), dp[i - 2] + abs(height[i] - height[i - 2]));
        }
        return dp[n - 1];
    }
};

int main() {
    Solution s;
    int n;
    cin >> n;
    vector<int> height = {30, 20, 50, 10, 40};
    cout << s.minCost(height) << endl;
    return 0;
}