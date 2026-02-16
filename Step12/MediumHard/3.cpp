#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), l = 0, r = 0;
        int jump_count = 0;
        while(r < n-1) {
            int farthest = 0;
            for(int i = l; i <= r; i++) {
                farthest = max(farthest, i+nums[i]);
            }
            l = r + 1;
            r = farthest;
            jump_count++;
        }
        return jump_count;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {2,3,1,1,4};
    cout << sol.jump(nums) << endl; // Output: 2
    return 0;
}