#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    int f(vector<int>& nums, int start, int end) {
        int n = nums.size();
        int prev_1 = nums[start];
        int prev_2 = 0;
        for(int i = start + 1; i < end; i++) {
            int take = nums[i];
            if(i > start + 1) {
                take += prev_2;
            }
            int curr = max(take, prev_1);
            prev_2 = prev_1;
            prev_1 = curr;
        }
        return prev_1;
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        return max(f(nums, 0, n - 1), f(nums, 1, n));
    }
};

int main() {
    Solution s;
    int n;
    cin >> n;
    vector<int> nums = {1, 2, 3, 1};
    cout << s.rob(nums) << endl;
    return 0;
}
