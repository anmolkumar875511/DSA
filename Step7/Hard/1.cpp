#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    void f(int i, vector<vector<bool>>& isPal, string s, vector<string>& v, vector<vector<string>>& ans) {
        int n = s.size();
        if(i >= n) {
            ans.push_back(v);
            return;
        }
        for(int idx = i; idx < n; idx++) {
            if(isPal[i][idx] == true) {
                v.push_back(s.substr(i, idx - i + 1));
                f(idx + 1, isPal, s, v, ans);
                v.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> isPal(n, vector<bool> (n, false));
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                
                if (s[i] == s[j]) {
                    if (len <= 2 || isPal[i + 1][j - 1]) {
                        isPal[i][j] = true;
                    }
                }
            }
        }
        vector<string> v;
        vector<vector<string>> ans;
        f(0, isPal, s, v, ans);
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<string>> ans = s.partition("aab");
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}