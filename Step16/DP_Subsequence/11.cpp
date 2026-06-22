#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<int> dp(n + 1, 0);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= i; j++) {
                dp[i + 1] = max(dp[i + 1], price[j] + dp[i - j]);
            }
        }
        return dp[n];
    }
};

int main() {
    Solution sol;
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    int ans = sol.cutRod(price);
    cout << ans << endl;
    return 0;
}
