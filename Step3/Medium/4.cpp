#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN, currSum = 0;
        for(int num : nums) {
            currSum = max(currSum + num, num);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    int result = sol.maxSubArray(nums);

    cout << "Maximum Subarray Sum: " << result << endl;
    return 0;
}