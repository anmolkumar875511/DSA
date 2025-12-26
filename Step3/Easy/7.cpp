#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] != 0) nums[j++] = nums[i];
        }
        while(j < n) nums[j++] = 0;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {0, 1, 0, 3, 12};
    sol.moveZeroes(nums);
    cout << "Array after moving zeroes: ";
    for(int num : nums){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}