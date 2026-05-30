#include<iostream>
#include<vector>
#include<deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;

        for (int i = 0; i < n; i++) {
            if (!dq.empty() && dq.front() <= i - k) 
                dq.pop_front();
            while (!dq.empty() && nums[dq.back()] <= nums[i]) 
                dq.pop_back();

            dq.push_back(i);
            if (i >= k - 1) 
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int> result = sol.maxSlidingWindow(nums, k);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}