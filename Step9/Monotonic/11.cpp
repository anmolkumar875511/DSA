#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols + 1, 0);
        int maxArea = 0;
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        
        return maxArea;
    }

private:
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
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};
    int ans = sol.maximalRectangle(matrix);
    cout << ans << endl;
    return 0;
}