#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
private:
    int longestCommonSubsequence(string s, string t) {
        int n = s.size();
        vector<int> curr(n + 1, 0), prev(n + 1, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(s[i] == t[j]) {
                    curr[j + 1] = 1 + prev[j];
                }
                else {
                    curr[j + 1] = max(curr[j], prev[j + 1]);
                }
            }
            prev = curr;
        }
        return prev[n];
    }
public:
    int minInsertions(string s) {
        int n = s.size();
        string t = s;
        reverse(s.begin(), s.end());
        return n - longestCommonSubsequence(s, t);
    }
};


int main() {
    Solution s;
    cout << s.minInsertions("zzazz") << endl;
    return 0;
}