#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();
        int i = n - 2;
        while(i > -1 && nums[i] >= nums[i + 1]) i--;
        
        if(i >= 0) {
            int j = n - 1;
            while(nums[j] <= nums[i]) j--;
            swap(nums[j], nums[i]);
        }

        reverse(nums.begin() + i + 1, nums.end());
    }
};

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    sol.nextPermutation(nums);

    cout << "Next Permutation: ";
    for(int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}