#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> next;
        stack<int> st;
        int n = nums2.size();
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && st.top() <= nums2[i]) st.pop();
            if(st.empty()) next[nums2[i]] = -1;
            else next[nums2[i]] = st.top();
            st.push(nums2[i]);
        }
        n = nums1.size();
        vector<int> ans(n);
        for(int i = 0; i < n; i++) ans[i] = next[nums1[i]];
        return ans;
    }
};


int main() {
    Solution sol;
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> ans = sol.nextGreaterElement(nums1, nums2);
    for(int num : ans) cout << num << " ";
    return 0;
}