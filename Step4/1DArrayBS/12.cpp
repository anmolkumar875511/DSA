#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while(low < high) {
            int mid = low + ((high - low) / 2);
            if(( mid % 2 == 0 && nums[mid] == nums[mid + 1]) || ( mid % 2 == 1 && nums[mid] == nums[mid - 1])) {
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
    vector<int> nums = {1,1,2,3,3,4,4,8,8}; // Example input
    int singleElement = sol.singleNonDuplicate(nums);
    cout << "The single non-duplicate element is: " << singleElement << endl;
    return 0;
}