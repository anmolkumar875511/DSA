#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while(low < high) {
            int mid = low + ((high - low) / 2);

            if(nums[mid] < nums[mid + 1]) {
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
    vector<int> nums = {1, 3, 20, 4, 1, 0, -1}; // Example input
    int peakIndex = sol.findPeakElement(nums);
    cout << "Peak element is at index: " << peakIndex << endl;
    return 0;
}