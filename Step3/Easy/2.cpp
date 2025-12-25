#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution {
public:
    int secondLargestElement(vector<int>& nums) {
        if (nums.size() < 2) return -1;

        int maxE = INT_MIN;
        int maxE2 = INT_MIN;

        for (int num : nums) {
            if (num > maxE) {
                maxE2 = maxE;
                maxE = num;
            }
            else if (num < maxE && num > maxE2) {
                maxE2 = num;
            }
        }

        if (maxE2 == INT_MIN) return -1;
        return maxE2;
    }
};


int main(){
    Solution sol;
    vector<int> nums = {3, 5, 7, 2, 8, -1, 4};
    int secondLargest = sol.secondLargestElement(nums);
    cout << "The second largest element in the array is: " << secondLargest << endl;
}
