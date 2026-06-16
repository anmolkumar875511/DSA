#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 2, 1);
        dp[2] = 2;
        for(int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

int main() {
    Solution s;
    int n;
    cin >> n;
    cout << s.climbStairs(n) << endl;
    return 0;
}