#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();
        vector<bool> prev(m + 1, false), curr(m + 1, false);
        prev[0] = true;
        for(int i = 0; i < n; i++) {
            curr[0] = prev[0] && (p[i] == '*');
            for(int j = 0; j < m; j++) {
                if(p[i] == s[j] || p[i] == '?') {
                    curr[j + 1] = prev[j];
                }
                else if(p[i] == '*') {
                    curr[j + 1] = curr[j] || prev[j + 1];
                }
                else {
                    curr[j + 1] = false;
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};

int main() {
    Solution obj;
    string s = "aa";
    string p = "a";
    cout << obj.isMatch(s, p) << endl;
    return 0;
}
