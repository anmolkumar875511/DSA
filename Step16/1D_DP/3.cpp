#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int frogJump(vector<int>& heights, int k) {
        int n = heights.size();
        vector<int> dp(n, 1e9);
        dp[0] = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < min(n, i + k + 1); j++) {
                dp[j] = min(dp[j], dp[i] + abs(heights[i] - heights[j]));
            }
        }
        return dp[n - 1];
    }
};

int main() {
    Solution s;
    int n;
    cin >> n;
    vector<int> heights = {30, 20, 50, 10, 40};
    int k;
    cin >> k;
    cout << s.frogJump(heights, k) << endl;
    return 0;
}