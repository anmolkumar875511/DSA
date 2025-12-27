#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {

        int ptr0 = 0, ptr1 = 0, ptr2 = nums.size() - 1;

        while(ptr1 <= ptr2){
            if(nums[ptr1] == 0) swap(nums[ptr0++], nums[ptr1++]);
            else if(nums[ptr1] == 1) ptr1++;
            else swap(nums[ptr2--], nums[ptr1]);
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    
    sol.sortColors(nums);
    
    cout << "Sorted colors: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}