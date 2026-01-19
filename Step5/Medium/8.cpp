#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        int idx = 0;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(s[i] != ' ') {
                if(idx != 0) {
                    s[idx++] = ' ';
                }
                
                int j = i;
                while(j < n && s[j] != ' ') {
                    s[idx++] = s[j++];
                }

                reverse(s.begin() + idx - j + i, s.begin() + idx);
                i = j;
            }
        }
        s.erase(s.begin() + idx, s.end());
        return s;
    }
};


int main() {
    Solution sol;
    string s = "  hello world  ";
    cout << '"' << sol.reverseWords(s) << '"' << endl; // Output: "world hello"
    return 0;
}