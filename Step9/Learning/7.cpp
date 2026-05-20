#include<iostream>
#include<stack>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> map = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        for(char c : s) {
            if(c == '(' || c == '{' || c == '[') st.push(c);
            else {
                if(st.empty()) return false;
                char c2 = st.top();
                st.pop();
                if(c2 != map[c]) return false;
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};

int main() {
    Solution s;
    cout << s.isValid("()") << endl;
    cout << s.isValid("()[]{}") << endl;
    cout << s.isValid("(]") << endl;
    cout << s.isValid("([)]") << endl;
    cout << s.isValid("{[]}") << endl;
    return 0;
}