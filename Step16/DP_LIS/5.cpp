#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& s, const string& t) {
            return s.size() < t.size();
        });
        int n = words.size();
        unordered_map<string, int> dp;
        int max_len = 0;
        for(int i = 0; i < n; i++) {
            dp[words[i]] = 1;
            for(int j = 0; j < words[i].size(); j++) {
                string w = words[i].substr(0, j) + words[i].substr(j + 1);
                if(dp.count(w)) {
                    dp[words[i]] = max(dp[words[i]], 1 + dp[w]);
                }
            }
            max_len = max(max_len, dp[words[i]]);
        }
        return max_len;
    }
};

int main() {
    Solution sol;
    vector<string> words = {"a","b","ba","bca","bda","bdca"};
    cout << sol.longestStrChain(words);
    return 0;
}