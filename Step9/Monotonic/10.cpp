#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {

        int ans = 0;
        stack<int> st;
        int n = heights.size();
        vector<int> NSE(n, n), PSE(n, -1);

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(!st.empty()) NSE[i] = st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(!st.empty()) PSE[i] = st.top();
            st.push(i);
        }

        for(int i = 0; i < n; i++) {
            int a = heights[i] * (NSE[i] - PSE[i] - 1);
            ans = max(ans, a);
        }

        return ans;
    }
};


int main() {
    Solution sol;
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    int ans = sol.largestRectangleArea(heights);
    cout << ans << endl;
    return 0;
}