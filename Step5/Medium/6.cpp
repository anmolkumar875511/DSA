#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0;
        int maxLen = 1;

        auto expand = [&](int left, int right) {
            while(left >= 0 && right < n && s[left] == s[right]) {
                if(maxLen < right - left + 1) {
                    maxLen = right - left + 1;
                    start = left;
                }
                left--;
                right++;
            }
        };

        for(int i = 0; i < n; i++) {
            expand(i, i);
            expand(i, i + 1);
        }
        return s.substr(start, maxLen);
    }
};


int main() {
    Solution sol;
    string s = "babad";
    string result = sol.longestPalindrome(s);
    cout << "Longest palindromic substring: " << result << endl;
    return 0;
}