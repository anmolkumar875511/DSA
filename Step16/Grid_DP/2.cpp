#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(n > m) swap(m, n);
        vector<int> dp(n, 1);
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[j] = dp[j] + dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};

int main() {
    Solution s;
    int m = 3, n = 5;
    cout << s.uniquePaths(m, n) << endl;
    return 0;
}