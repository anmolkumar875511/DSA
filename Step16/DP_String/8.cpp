#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<unsigned long long> dp(m + 1, 0);
        dp[0] = 1LL;
        for(int i = 1; i <= n; i++) {
            for(int j = m; j > 0; j--) {
                if(s[i - 1] == t[j - 1]) {
                    dp[j] = dp[j - 1] + dp[j];
                }
            }
        }
        return dp[m];
    }
};

int main() {
    Solution solution;
    string s = "rabbbit";
    string t = "rabbit";
    cout << solution.numDistinct(s, t) << endl;
    return 0;
}