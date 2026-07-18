#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long XOR = 0;
        for(int num : nums) {
            XOR = XOR ^ num;
        }
        int right_most = (XOR & (XOR - 1)) ^ XOR;
        int b1 = 0, b2 = 0;
        for(int num : nums) {
            if(num & right_most) {
                b1 = b1 ^ num;
            }
            else {
                b2 = b2 ^ num;
            }
        }
        return {b1, b2};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    vector<int> ans = sol.singleNumber(nums);
    for(int num : ans) cout << num << " ";
    return 0;
}