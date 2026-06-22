#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    int longCommSubstr(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        int ans = 0;
        vector<int> prev(m + 1, 0), curr(m + 1, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(s1[i] == s2[j]) {
                    curr[j + 1] = 1 + prev[j];
                    ans = max(ans, curr[j + 1]);
                }
                else {
                    curr[j + 1] = 0;
                }
            }
            prev = curr;
        }
        return ans;
    }
};


int main() {
    Solution s;
    cout << s.longCommSubstr("abcde", "ace") << endl;
    return 0;
}