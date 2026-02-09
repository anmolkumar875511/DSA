#include<iostream>
#include<vector>    
using namespace std;

class Solution {
public:
    int atMost(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        int i = 0, res = 0, sum = 0;
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            while (sum > goal) {
                sum -= nums[i++];
            }
            res += j - i + 1; 
        }
        return res;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;
    cout << sol.numSubarraysWithSum(nums, goal) << endl; // Output: 4
    return 0;
}