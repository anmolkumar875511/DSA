#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int num : nums) {
            sum += num;
        }
        int k = sum / 2;
        
        vector<bool> curr(k + 1, false), prev(k + 1, false);
        prev[0] = curr[0] = true;
        if(nums[0] <= k) {
            prev[nums[0]] = true;
        }
        for(int i = 1; i < n; i++) {
            for(int j = 1; j <= k; j++) {
                bool not_take = prev[j];
                bool take = false;
                if(nums[i] <= j) {
                    take = prev[j - nums[i]];
                }
                curr[j] = not_take | take;
            }
            prev = curr;
        }
        int t = 0;
        int i = k;
        while(prev[i] == false) {
            i--;
        }
        return sum - (2 * i);
    }
};


int main() {
    Solution sol;
    vector<int> nums = {1, 6, 11, 5};
    cout << sol.minDifference(nums) << endl;
    return 0;
}
