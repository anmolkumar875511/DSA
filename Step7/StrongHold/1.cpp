#include<iostream>
#include<string>
#include<climits>
using namespace std;

class Solution {
public:
    int Atoi(long n, string s, int i, int sign){
        if(i == s.size() || !(isdigit(s[i]))) {
            return n;
        }
        else {
            n = n * 10 + (s[i] - '0');

            if(n*sign >= INT_MAX) return INT_MAX;
            if(n*sign <= INT_MIN) return INT_MIN;

            return Atoi(n, s, i+1, sign);
        }
    }

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

        res = Atoi(res, s, i, sign);
        return (int)(res * sign);
    }
};


int main() {
    Solution sol;
    string str = "   -42";
    cout << sol.myAtoi(str) << endl; // Output: -42
    return 0;
}