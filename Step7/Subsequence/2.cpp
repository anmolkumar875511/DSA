#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void insert(vector<string>& v, string s, int n, int depth) {
        if(n == 0) {
            if(depth == 0) {
                v.push_back(s);
            }
            else {
                s.push_back(')');
                insert(v, s, n, depth-1);
            }
        }
        else {
            if(depth == 0) {
                s.push_back('(');
                insert(v, s, n-1, 1);
            }
            else {
                s.push_back('(');
                insert(v, s, n-1, depth+1);
                s.pop_back();
                s.push_back(')');
                insert(v, s, n, depth-1);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        vector<string> v;
        insert(v, s, n, 0);
        return v;
    }
};


int main() {
    Solution sol;
    int n = 3;
    vector<string> result = sol.generateParenthesis(n);
    for (const string& str : result) {
        cout << str << endl;
    }
    return 0;
}