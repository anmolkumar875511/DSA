#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int findBound(vector<int>&nums, int target, bool isFirst) {

        int low = 0;
        int high = nums.size() - 1;
        int bound = -1;

        while(low <= high) {
            int mid = low + ((high - low) / 2);

            if(nums[mid] < target) {
                low = mid + 1;
            }
            else if(nums[mid] > target) {
                high = mid - 1;
            }
            else {
                bound = mid;
                if(isFirst) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }

        }
        return bound;

    }

    vector<int> searchRange(vector<int>& nums, int target) {

        int first = findBound(nums, target, true);

        if(first == -1) {
            return {first, first};
        }

        int last = findBound(nums, target, false);

        return {first, last};
    }
};


int main() {
    Solution sol;
    vector<int> nums = {5,7,7,8,8,10}; // Example input
    int target = 8; // Example target
    vector<int> result = sol.searchRange(nums, target);
    cout << "First and Last positions of " << target << ": [" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}