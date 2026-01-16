#include<iostream>
#include<string>
#include<climits>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int sign = 1;
        long res = 0;

        while(i < s.size() && s[i] == ' ') {
            i++;
        }
        if(i < s.size() && s[i] == '-') {
            sign = -1;
            i++;
        }
        else if(i < s.size() && s[i] == '+') {
            i++;
        }

        while(i < s.size() && isdigit(s[i])) {
            res = res * 10 + (s[i] - '0');

            if(res * sign >= INT_MAX) {
                return INT_MAX;
            }
            else if(res * sign <= INT_MIN) {
                return INT_MIN;
            }
            i++;
        }
        return (int)(res * sign);
    }
};


int main() {
    Solution sol;
    string s = "42";
    cout << sol.myAtoi(s) << endl;  // Output: 42
    s = "   -42";
    cout << sol.myAtoi(s) << endl;  // Output: -42
    s = "4193 with words";
    cout << sol.myAtoi(s) << endl;  // Output: 4193
    return 0;
}