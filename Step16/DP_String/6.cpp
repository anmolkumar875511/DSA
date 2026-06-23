#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
private:
    int longestCommonSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<int> curr(m + 1, 0), prev(m + 1, 0);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(s[i] == t[j]) {
                    curr[j + 1] = 1 + prev[j];
                }
                else {
                    curr[j + 1] = max(curr[j], prev[j + 1]);
                }
            }
            prev = curr;
        }
        return prev[m];
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int lcs = longestCommonSubsequence(word1, word2);
        return m + n - (2 * lcs);
    }
};


int main() {
    Solution s;
    cout << s.minDistance("horse", "ros") << endl;
    return 0;
}