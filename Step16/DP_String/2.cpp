#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string printLongestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(text1[i - 1] == text2[j - 1]) {
                    dp[j][i] = 1 + dp[j - 1][i - 1];
                }
                else {
                    dp[j][i] = max(dp[j - 1][i], dp[j][i - 1]);
                }
            }
        }
        string ans = "";
        int i = n, j = m;
        while(i > 0 && j > 0) {
            if(text1[i - 1] == text2[j - 1]) {
                ans += text1[i - 1];
                i--;
                j--;
            }
            else if(dp[j - 1][i] > dp[j][i - 1]) {
                j--;
            }
            else {
                i--;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.printLongestCommonSubsequence("abcde", "ace") << endl;
    return 0;
}