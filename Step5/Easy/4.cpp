#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        
        for(int i = 0; i < strs[0].size(); i++) {
            char c = strs[0][i];
            for(int j = 1; j < strs.size(); j++) {
                if(i == strs[j].size() || strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};


int main() {
    Solution sol;
    vector<string> strs = {"flower", "flow", "flight"};
    cout << '"' << sol.longestCommonPrefix(strs) << '"' << endl; // Output: "fl"
    return 0;
}