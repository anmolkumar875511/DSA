#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    pair<int, int> maxSubArray(vector<int>& nums) {

        int maxSum = INT_MIN;
        int currSum = 0;
        int n = nums.size();
        int start = 0, end = 0;

        for(int i = 0; i < n; i++) {
            if(currSum + nums[i] < nums[i]) {
                currSum = nums[i];
                start = i;
            } else {
                currSum += nums[i];
            }
            if(currSum > maxSum) {
                maxSum = currSum;
                end = i;
            }
        }

        return {start, end};
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
    pair<int, int> result = sol.maxSubArray(nums);

    cout << "Maximum Subarray Indices: [" << result.first << ", " << result.second << "]" << endl;
    for(int i = result.first; i <= result.second; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}