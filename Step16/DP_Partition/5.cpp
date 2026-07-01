#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    int countWays(string &s) {
        int n = s.length();
        if (n == 0) return 0;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));

        for (int len = 1; len <= n; len += 2) {
            for (int i = 0; i <= n - len; i += 2) {
                int j = i + len - 1;
                
                if (len == 1) {
                    if (s[i] == 'T') dp[i][i][1] = 1;
                    else dp[i][i][0] = 1;
                    continue;
                }
                for (int k = i + 1; k < j; k += 2) {
                    long long leftT = dp[i][k - 1][1];
                    long long leftF = dp[i][k - 1][0];
                    long long rightT = dp[k + 1][j][1];
                    long long rightF = dp[k + 1][j][0];

                    if (s[k] == '&') {
                        dp[i][j][1] += (leftT * rightT);
                        dp[i][j][0] += (leftT * rightF) + (leftF * rightT) + (leftF * rightF);
                    } 
                    else if (s[k] == '|') {
                        dp[i][j][1] += (leftT * rightT) + (leftT * rightF) + (leftF * rightT);
                        dp[i][j][0] += (leftF * rightF);
                    } 
                    else if (s[k] == '^') {
                        dp[i][j][1] += (leftT * rightF) + (leftF * rightT);
                        dp[i][j][0] += (leftT * rightT) + (leftF * rightF);
                    }
                }
            }
        }
        return dp[0][n - 1][1];
    }
};

int main() {
    Solution sol;
    string S = "T|T&F^T";
    cout << sol.countWays(S) << endl;
    return 0;
}