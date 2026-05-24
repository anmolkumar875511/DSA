#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        stack<int> st;

        for(int a : asteroids) {

            bool destroyed = false;

            while(!st.empty() && st.top() > 0 && a < 0) {

                if(abs(a) > st.top()) {
                    st.pop();
                }

                else if(abs(a) == st.top()) {
                    st.pop();
                    destroyed = true;
                    break;
                }

                else {
                    destroyed = true;
                    break;
                }
            }

            if(!destroyed) {
                st.push(a);
            }
        }

        vector<int> ans(st.size());

        for(int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> asteroids = {5, 10, -5};
    vector<int> ans = sol.asteroidCollision(asteroids);
    for(int num : ans) cout << num << " ";
    return 0;
}