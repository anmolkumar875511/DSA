#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
private:
    string longestCommonSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(s[i] == t[j]) {
                    dp[i + 1][j + 1] = 1 + dp[i][j];
                }
                else {
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }
        string ans = "";
        int i = n, j = m;
        while(i > 0 && j > 0) {
            if(s[i - 1] == t[j - 1]) {
                ans.push_back(s[i - 1]);
                i--;
                j--;
            }
            else if(dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            }
            else {
                j--;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
public:
    string shortestCommonSupersequence(string str1, string str2) {
        string str = longestCommonSubsequence(str1, str2);
        int n = str1.size(), m = str2.size(), o = str.size();
        int i = 0, j = 0, k = 0;
        string ans = "";
        while(i < n && j < m && k < o) {
            while(i < n && str1[i] != str[k]) {
                ans.push_back(str1[i]);
                i++;
            }
            while(j < m && str2[j] != str[k]) {
                ans.push_back(str2[j]);
                j++;
            }
            ans.push_back(str[k]);
            i++;
            j++;
            k++;
        }
        while(i < n) {
            ans.push_back(str1[i]);
            i++;
        }
        while(j < m) {
            ans.push_back(str2[j]);
            j++;
        }
        return ans;
    }
};


int main() {
    Solution s;
    cout << s.shortestCommonSupersequence("abac", "cab") << endl;
    return 0;
}