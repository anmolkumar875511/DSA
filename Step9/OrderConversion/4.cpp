#include<iostream>
#include<string>
#include<stack>
using namespace std;


class Solution {
  public:
    string preToInfix(string s) {
        stack<string> st;
        int n = s.size();
        
        for(int i = n - 1; i >= 0; i--) {
            char c = s[i];
            if(isalnum(c)) {
                st.push(string(1, c));
            }
            else {
                string s1 = st.top();
                st.pop();

                string s2 = st.top();
                st.pop();

                string expr = "(" + s1 + c + s2 + ")";
                st.push(expr);
            }
        }

        return st.top();
    }
};

int main() {
    Solution sol;
    string s = "*-A/BC-/AKL";
    cout << sol.preToInfix(s);
    return 0;
}