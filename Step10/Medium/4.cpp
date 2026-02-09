#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int max_len = 0, j = 0, max_count = 0;
        int freq[26] = {0};
        for(int i = 0; i < n; i++) {
            max_count = max(max_count, ++freq[s[i]-'A']);
            while(i-j+1 - max_count > k) {
                freq[s[j++]-'A']--;
            }
            max_len = max(max_len, i-j+1);
        }
        return max_len;
    }
};

int main() {
    Solution sol;
    string s = "AABABBA";
    int k = 1;
    cout << sol.characterReplacement(s, k) << endl; // Output: 4
    return 0;
}