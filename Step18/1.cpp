#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, cnt = 0;
        for(char c : s) {
            if(c == ')') {
                if(open > 0) {
                    open--;
                }
                else {
                    cnt++;
                }
            }
            else {
                open++;
            }
        }
         return open + cnt;
    }
};

int main() {
    Solution sol;
    string s = "())";
    cout << sol.minAddToMakeValid(s);
    return 0;
}