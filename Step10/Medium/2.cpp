#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zero_count = 0;
        int n = nums.size();
        int j = 0;
        int max_len = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                zero_count++;
                while(zero_count > k) {
                    if(nums[j] == 0) {
                        zero_count--;
                    }
                    j++;
                }
            }
            max_len = max(max_len, i-j+1);
        }
        return max_len;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1};
    int k = 2;
    cout << sol.longestOnes(nums, k) << endl; // Output: 6
    return 0;
}