#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> getFloorAndCeil(vector<int> nums, int x) {

        int low = 0;
        int high = nums.size() - 1;
        int floor = -1;
        int ceil = -1;

        while(low <= high) {
            int mid = low + ((high - low) / 2);

            if(nums[mid] > x) {
                ceil = nums[mid];
                high = mid - 1;
            }
            else if(nums[mid] < x) {
                floor = nums[mid];
                low = mid + 1;
            }
            else {
                return {x, x};
            }
        }
        return {floor, ceil};
        
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 8, 10, 10, 12, 19}; // Example input
    int x = 5; // Example target
    vector<int> result = sol.getFloorAndCeil(nums, x);
    cout << "Floor: " << result[0] << ", Ceil: " << result[1] << endl;
    return 0;
}