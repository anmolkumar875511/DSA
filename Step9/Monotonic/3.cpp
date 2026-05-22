#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> nextSmallerElements(const vector<int>& arr) {
        stack<int> st;
        vector<int> ans(arr.size(), -1);
        for(int i = arr.size() - 1; i >= 0; i--) {
            while(!st.empty() && st.top() >= arr[i]) st.pop();
            if(!st.empty()) ans[i] = st.top();
            st.push(arr[i]);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 3, 2, 4};
    vector<int> ans = sol.nextSmallerElements(arr);
    for(int num : ans) cout << num << " ";
    return 0;
}