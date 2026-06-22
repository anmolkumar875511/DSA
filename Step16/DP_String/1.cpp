#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
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
};

int main() {
    Solution s;
    cout << s.longestCommonSubsequence("abcde", "ace") << endl;
    return 0;
}