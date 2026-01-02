#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while(low < high) {
            int mid = low + ((high - low) / 2);
            if(nums[mid] > nums[high]) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        return nums[low];
    }
};


int main() {
    Solution sol;
    vector<int> nums = {3,4,5,1,2}; // Example input
    int minElement = sol.findMin(nums);
    cout << "Minimum element: " << minElement << endl;
    return 0;
}