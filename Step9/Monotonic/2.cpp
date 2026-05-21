#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> st, ans(n, -1);
        for(int i = 0; i < 2 * n; i++) {
            while(st.size() && nums[st.back()] < nums[i % n]) {
                ans[st.back()] = nums[i % n];
                st.pop_back();
            }
            st.push_back(i % n);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 1};
    vector<int> ans = sol.nextGreaterElements(nums);
    for(int num : ans) cout << num << " ";
    return 0;
}