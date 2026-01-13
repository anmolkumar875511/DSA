#include<iostream>
#include<string>
using namespace std;


class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        if(goal.size() != n) {
            return false;
        }
        
        for(int i = 0; i < n; i++) {
            if(s.substr(i, n) == goal.substr(0, n - i) && s.substr(0, i) == goal.substr(n - i, n - 1)) {
                return true;
            }
        }
        return false;
    }
};


int main() {
    Solution sol;
    string s = "abcde";
    string goal = "cdeab";
    cout << (sol.rotateString(s, goal) ? "true" : "false") << endl; // Output: true
    return 0;
}