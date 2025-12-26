#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        int idx;
        vector<int> rotated(n);
        for(int i = 0; i < n; i++){
            idx = (i + k) % n;
            rotated[idx] = nums[i];
        }
        for(int i = 0; i < n; i++){
            nums[i] = rotated[i];
        }
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;
    sol.rotate(nums, k);
    cout << "The rotated array is: ";
    for(int num : nums){
        cout << num << " ";
    }
    cout << endl;
}