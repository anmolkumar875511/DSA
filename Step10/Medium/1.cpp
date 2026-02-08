#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int count[128] = {0};
        int j = 0;
        int max_len = 0;
        for(int i = 0; i < n; i++) {
            count[s[i]]++;
            while(count[s[i]] > 1) {
                count[s[j]]--;
                j++;
            }
            max_len = max(max_len, i-j+1);
        }
        return max_len;
    }
};


int main() {
    Solution sol;
    string s = "abcabcbb";
    cout << sol.lengthOfLongestSubstring(s) << endl; // Output: 3
    return 0;
}