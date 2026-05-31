#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    string postToInfix(string &s) {
        stack<string> st;

        for(char c : s) {
            if(isalnum(c)) {
                st.push(string(1, c));
            }
            else {
                string s1 = st.top();
                st.pop();

                string s2 = st.top();
                st.pop();

                string expr = "(" + s2 + c + s1 + ")";
                st.push(expr);
            }
        }

        return st.top();
    }
};

int main() {
    Solution sol;
    string s = "ab*c+";
    cout << sol.postToInfix(s);
    return 0;
}