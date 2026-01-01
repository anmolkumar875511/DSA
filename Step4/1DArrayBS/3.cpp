#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int upperBound(vector<int> &nums, int x){

        int low = 0;
        int high = nums.size() - 1;
        int ans = nums.size();

        while(low <= high) {

            int mid = low + ((high - low) / 2);

            if(nums[mid] > x) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0,2,3,5,9,12}; // Example input
    int x = 5; // Example target
    int result = sol.upperBound(nums, x);
    cout << "Upper bound index of " << x << ": " << result << endl;
    return 0;
}