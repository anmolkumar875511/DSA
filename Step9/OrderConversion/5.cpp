#include<iostream>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    string postToPre(string s) {
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

                string expr = string(1, c) + s2 + s1;
                st.push(expr);
            }
        }

        return st.top();
    }
};

int main() {
    Solution sol;
    string s = "ab*c+";
    cout << sol.postToPre(s);
    return 0;
}