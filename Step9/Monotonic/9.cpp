#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {

        stack<char> st;

        for(char ch : num) {

            while(!st.empty() && st.top() > ch && k > 0) {
                st.pop();
                k--;
            }

            st.push(ch);
        }

        while(k > 0) {
            st.pop();
            k--;
        }

        string ans;

        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        int i = 0;
        while(i < ans.size() && ans[i] == '0') {
            i++;
        }

        ans = ans.substr(i);

        return ans.empty() ? "0" : ans;
    }
};

int main() {
    Solution sol;
    string num = "1432219";
    int k = 3;
    string ans = sol.removeKdigits(num, k);
    cout << ans << endl;
    return 0;
}