#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(i > maxReach) return false;
            maxReach = max(maxReach, i+nums[i]);
        }
        return maxReach > n-2;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,3,1,1,4};
    cout << sol.canJump(nums) << endl; // Output: 1 (true)
    return 0;
}
