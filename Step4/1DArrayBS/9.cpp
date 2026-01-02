#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return true;

            // Case 1: Duplicates — cannot decide
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
            }
            // Case 2: Left half is sorted
            else if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            // Case 3: Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return false;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {2,5,6,0,0,1,2}; // Example input
    int target = 0; // Example target
    bool result = sol.search(nums, target);
    cout << "Target " << target << (result ? " found." : " not found.") << endl;
    return 0;
}