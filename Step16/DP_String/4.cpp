#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
private:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(text1[i] == text2[j]) {
                    curr[j + 1] = 1 + prev[j];
                }
                else {
                    curr[j + 1] = max(prev[j + 1], curr[j]);
                }
            }
            prev = curr;
        }
        return prev[m];
    }
public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(s.begin(), s.end());
        return longestCommonSubsequence(s, t);
    }
};

int main() {
    Solution s;
    cout << s.longestPalindromeSubseq("bbbab") << endl;
    return 0;
}