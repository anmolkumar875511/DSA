#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int findPivot(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while(low <= high) {
            int mid = low + ((high - low) / 2);
            if(nums[mid] < nums[0]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return high;
    }

    int binarySearch(vector<int>& nums, int target, int low, int high) {
        while(low <= high) {
            int mid = low + ((high - low) / 2);
            if(nums[mid] > target) {
                high = mid - 1;
            }
            else if(nums[mid] < target) {
                low = mid + 1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int low = 0;
        int pivot = findPivot(nums);
        int high = nums.size() - 1;

        int leftSearch = binarySearch(nums, target, low, pivot);
        if(leftSearch > -1) {
            return leftSearch;
        }
        
        int rightSearch = binarySearch(nums, target, pivot + 1, high);
        return rightSearch;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {4,5,6,7,0,1,2}; // Example input
    int target = 0; // Example target
    int result = sol.search(nums, target);
    cout << "Index of target " << target << ": " << result << endl;
    return 0;
}