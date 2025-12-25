#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int largestElement(vector<int>& nums) {
        int maxE = INT_MIN;
        for(int num : nums){
            maxE = max(maxE, num);
        }
        return maxE;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {3, 5, 7, 2, 8, -1, 4};
    int largest = sol.largestElement(nums);
    cout << "The largest element in the array is: " << largest << endl;
}