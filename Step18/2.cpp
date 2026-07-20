#include<iostream>
#include<string>
using namespace std;

class Solution {
private:
    string f(string& s) {
        string res = "";
        int freq = 0;
        char ch = s[0];
        for(char c : s) {
            if(ch == c) {
                freq++;
            }
            else {
                res.push_back('0' + freq);
                res.push_back(ch);
                freq = 1;
                ch = c;
            }
        }
        res.push_back('0' + freq);
        res.push_back(s.back());
        return res;
    }
public:
    string countAndSay(int n) {
        string s = "1";
        for(int i = 1; i < n; i++) {
            s = f(s);
        }
        return s;
    }
};

int main() {
    Solution sol;
    int n = 5;
    cout << sol.countAndSay(n);
    return 0;
}