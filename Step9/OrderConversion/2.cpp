#include<iostream>
#include<string>
#include<unordered_map>
#include<stack>
#include<algorithm>
using namespace std;

class Solution {
private:
    int precedence(char op) {
        if(op == '^') return 3;
        if(op == '*' || op == '/') return 2;
        if(op == '+' || op == '-') return 1;
        return 0;
    }

public:
    string infixToPrefix(string s) {
        reverse(s.begin(), s.end());

        // Swap brackets
        for(char &c : s) {
            if(c == '(') c = ')';
            else if(c == ')') c = '(';
        }

        stack<char> st;
        string postfix;

        for(char c : s) {
            if(isalnum(c)) {
                postfix.push_back(c);
            }
            else if(c == '(') {
                st.push(c);
            }
            else if(c == ')') {
                while(!st.empty() && st.top() != '(') {
                    postfix.push_back(st.top());
                    st.pop();
                }
                if(!st.empty()) st.pop();
            }
            else { // operator
                while(!st.empty() &&
                      st.top() != '(' &&
                      (precedence(st.top()) > precedence(c) ||
                       (precedence(st.top()) == precedence(c) && c != '^')))
                {
                    postfix.push_back(st.top());
                    st.pop();
                }
                st.push(c);
            }
        }

        while(!st.empty()) {
            postfix.push_back(st.top());
            st.pop();
        }

        reverse(postfix.begin(), postfix.end());
        return postfix;
    }
};


int main() {
    Solution sol;
    string s = "a+b*(c^d-e)^(f+g*h)-i";
    string ans = sol.infixToPrefix(s);
    cout << ans << endl;
    return 0;
}