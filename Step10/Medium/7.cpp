#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int res = 0;
        int lastSeen[3] = {-1, -1, -1};
        for(int i = 0; i < n; i++) {
            lastSeen[s[i]-'a'] = i;
            if(lastSeen[0] >= 0 && lastSeen[1] >= 0 && lastSeen[2] >= 0) {
                res += min(lastSeen[0], min(lastSeen[1], lastSeen[2])) + 1;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;
    string s = "abcabc";
    cout << sol.numberOfSubstrings(s) << endl; // Output: 10
    return 0;
}