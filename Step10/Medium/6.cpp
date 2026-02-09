#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        if (k < 0) return 0;
        int left = 0, count = 0, odd_cnt = 0;
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] & 1) odd_cnt++;
            while (odd_cnt > k) {
                if (nums[left++] & 1) odd_cnt--;
            }
            count += (right - left + 1);
        }
        return count;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};


int main() {
    Solution sol;
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;
    cout << sol.numberOfSubarrays(nums, k) << endl; // Output: 2
    return 0;
}
