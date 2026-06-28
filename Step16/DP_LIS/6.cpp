#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    int longestBitonicSequence(int n, vector<int> &nums) {
        vector<int> dp_i(n, 1), dp_d(n, 1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    dp_i[i] = max(dp_i[i], 1 + dp_i[j]);
                }
            }
        }
        for(int i = n - 1; i >= 0; i--) {
            for(int j = n - 1; j > i; j--) {
                if(nums[i] > nums[j]) {
                    dp_d[i] = max(dp_d[i], 1 + dp_d[j]);
                }
            }
        }
        int max_len = 0;
        for(int i = 0; i < n; i++) {
            if(dp_i[i] > 1 && dp_d[i] > 1) {
                max_len = max(max_len, dp_i[i] + dp_d[i] - 1);
            }
        }
        return max_len;
    }
};

int main() {
    Solution sol;
    int n = 4;
    vector<int> nums = {1, 3, 2, 4};
    cout << sol.longestBitonicSequence(n, nums);
    return 0;
}
