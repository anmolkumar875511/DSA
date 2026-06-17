#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev_1 = nums[0];
        int prev_2 = 0;
        for(int i = 1; i < n; i++) {
            int take = nums[i];
            if(i > 1) {
                take += prev_2;
            }
            int curr = max(take, prev_1);
            prev_2 = prev_1;
            prev_1 = curr;
        }
        return prev_1;
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