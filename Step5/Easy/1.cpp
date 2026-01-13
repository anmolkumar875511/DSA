#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int depth = 0;
        for(char c : s) {
            if(c == '(' && depth++ > 0) {
                ans += c;
            }
            if(c == ')' && --depth > 0) {
                ans += c;
            }
        }
        return ans;
    }
};


int main() {
    Solution sol;
    string s = "(()())(())";
    cout << sol.removeOuterParentheses(s) << endl; // Output: "()()()"
    return 0;
}