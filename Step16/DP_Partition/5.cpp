#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    int countWays(string &S) {
        int n = S.length();
        if (n == 0) return 0;
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(2, 0)));
        for (int i = 0; i < n; i += 2) {
            if (S[i] == 'T') {
                dp[i][i][1] = 1;
            } else {
                dp[i][i][0] = 1;
            }
        }
        for (int len = 3; len <= n; len += 2) {
            for (int i = 0; i <= n - len; i += 2) {
                int j = i + len - 1;
                
                for (int k = i + 1; k <= j - 1; k += 2) {
                    long long leftT = dp[i][k - 1][1];
                    long long leftF = dp[i][k - 1][0];
                    long long rightT = dp[k + 1][j][1];
                    long long rightF = dp[k + 1][j][0];
    
                    if (S[k] == '&') {
                        dp[i][j][1] = (dp[i][j][1] + (leftT * rightT) % MOD) % MOD;
                        dp[i][j][0] = (dp[i][j][0] + (leftT * rightF) % MOD + 
                                                     (leftF * rightT) % MOD + 
                                                     (leftF * rightF) % MOD) % MOD;
                    } 
                    else if (S[k] == '|') {
                        dp[i][j][1] = (dp[i][j][1] + (leftT * rightT) % MOD + 
                                                     (leftT * rightF) % MOD + 
                                                     (leftF * rightT) % MOD) % MOD;
                        dp[i][j][0] = (dp[i][j][0] + (leftF * rightF) % MOD) % MOD;
                    } 
                    else if (S[k] == '^') {
                        dp[i][j][1] = (dp[i][j][1] + (leftT * rightF) % MOD + 
                                                     (leftF * rightT) % MOD) % MOD;
                        dp[i][j][0] = (dp[i][j][0] + (leftT * rightT) % MOD + 
                                                     (leftF * rightF) % MOD) % MOD;
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