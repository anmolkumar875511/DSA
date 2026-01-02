#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int findKRotation(vector<int> &nums)  {
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
        return low;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {15, 18, 2, 3, 6, 12}; // Example input
    int rotationCount = sol.findKRotation(nums);
    cout << "Array is rotated " << rotationCount << " times." << endl;
    return 0;
}