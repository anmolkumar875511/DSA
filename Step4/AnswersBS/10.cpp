#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    bool canSplitted(vector<int>& nums, int maxSum, int num) {
        int sum = 0;
        int cnt = 1;

        for(int n : nums) {
            if(sum + n > maxSum) {
                sum = n;
                cnt++;
                if(cnt > num) {
                    return false;
                }
            }
            else {
                sum = sum + n;
            }
        }
        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = 0;
        int high = 0;
        for(int num : nums) {
            low = max(low, num);
            high = high + num;
        }
        int ans = high;

        while(low <= high) {
            int mid = low + ((high - low) / 2);

            if(canSplitted(nums, mid, k)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {7,2,5,10,8};
    int k = 2;
    cout << sol.splitArray(nums, k) << endl; // Output: 18
    return 0;
}