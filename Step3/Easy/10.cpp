#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int num : nums) {
            sum = sum + num;
        }
        return (n * (n + 1)) / 2 - sum;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 0, 1};
    int missing = sol.missingNumber(nums);
    cout << "The missing number is: " << missing << endl;
    return 0;
}