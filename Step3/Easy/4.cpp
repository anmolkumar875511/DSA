#include<iostream>
#include<vector>
using namespace std;   

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int j = 0;
        for(int i = 1; i < n; i++) {
            if(nums[i - 1] != nums[i]) {
                j++;
                nums[j] = nums[i];
            }
        }
        return ++j;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5};
    int newLength = sol.removeDuplicates(nums);
    cout << "The length of the array after removing duplicates is: " << newLength << endl;
    cout << "The modified array is: ";
    for(int i = 0; i < newLength; i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}