#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int sumD(vector<int>& nums, int divisor) {
        int sumT = 0;
        for(int num : nums) {
            sumT = sumT + ((num + divisor - 1) / divisor);
        }
        return sumT;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = 0;
        for (int num : nums) {
            high = max(high, num);
        }
        int ans = high;

        while(low <= high) {
            int mid = low + ((high - low) / 2);

            if(sumD(nums, mid) > threshold) {
                low = mid + 1;
            }
            else {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,2,5,9}; // Example input for nums
    int threshold = 6; // Example input for threshold
    int result = sol.smallestDivisor(nums, threshold);
    cout << "Smallest divisor: " << result << endl;
    return 0;
}