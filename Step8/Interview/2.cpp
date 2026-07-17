#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int m = 0;
        for(int num : nums) {
            m = m ^ num;
        }
        return m;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4,1,2,1,2};
    cout << sol.singleNumber(nums);
    return 0;
}