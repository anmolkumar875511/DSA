#include<iostream>
#include<string>
#include<unordered_map>
#include<stack>
using namespace std;

class Solution {
private:
    unordered_map<char, int> order = {
        {'^', 3},
        {'*', 2},
        {'/', 2},
        {'+', 1},
        {'-', 1}
    };

public:
    string infixToPostfix(string& s) {
        string ans;
        stack<char> st;

        for(char c : s) {

            if(isalnum(c)) {
                ans.push_back(c);
            }

            else if(c == '(') {
                st.push(c);
            }

            else if(c == ')') {
                while(!st.empty() && st.top() != '(') {
                    ans.push_back(st.top());
                    st.pop();
                }
                if(!st.empty()) st.pop();
            }

            else {
                while(!st.empty() &&
                      st.top() != '(' &&
                      (order[c] < order[st.top()] ||
                       (order[c] == order[st.top()] && c != '^'))) {

                    ans.push_back(st.top());
                    st.pop();
                }
                st.push(c);
            }
        }

        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};


int main() {
    Solution sol;
    string s = "a+b*(c^d-e)^(f+g*h)-i";
    string ans = sol.infixToPostfix(s);
    cout << ans << endl;
    return 0;
}