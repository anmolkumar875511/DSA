#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;
        int mid = low + ((high - low) / 2);

        while(low <= high) {
            if(nums[mid] > target) {
                high = mid - 1;
            }
            else if(nums[mid] < target) {
                low = mid + 1;
            }
            else {
                return mid;
            }

            mid = low + ((high - low) / 2);
        }
        return -1;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {-1,0,3,5,9,12}; // Example input
    int target = 9; // Example target
    int result = sol.search(nums, target);
    cout << "Index of target " << target << ": " << result << endl;
    return 0;
}