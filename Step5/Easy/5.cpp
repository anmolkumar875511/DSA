#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> s2t;
        unordered_map<char, char> t2s;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(s2t.count(s[i]) && s2t[s[i]] != t[i]) {
                return false;
            }
            if(t2s.count(t[i]) && t2s[t[i]] != s[i]) {
                return false;
            }
            s2t[s[i]] = t[i];
            t2s[t[i]] = s[i];
        }
        return true;
    }
};


int main() {
    Solution sol;
    string s = "egg";
    string t = "add";
    cout << (sol.isIsomorphic(s, t) ? "true" : "false") << endl; // Output: true
    return 0;
}