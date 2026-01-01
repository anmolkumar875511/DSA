#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    int lowerBound(vector<int> &nums, int x){

        int low = 0;
        int high = nums.size() - 1;
        int ans = nums.size();
        
        while(low <= high) {

            int mid = low + ((high - low) / 2);

            if(nums[mid] >= x) {
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
    int x = 4; // Example target
    int result = sol.lowerBound(nums, x);
    cout << "Lower bound index of " << x << ": " << result << endl;
    return 0;
}