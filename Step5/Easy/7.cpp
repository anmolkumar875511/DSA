#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        if(t.size() != n) {
            return false;
        }

        int count[26] = {0};
        for(int i = 0; i < n; i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }
        for(int i = 0; i < 26; i++) {
            if(count[i] != 0) {
                return false;
            }
        }
        return true;
    }
};



int main() {
    Solution sol;
    string s = "anagram";
    string t = "nagaram";
    cout << (sol.isAnagram(s, t) ? "true" : "false") << endl; // Output: true
    return 0;
}