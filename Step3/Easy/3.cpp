#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i = 1; i < n; i++){
            if(nums[i - 1] > nums[i]) cnt++;
            if((cnt == 1 && nums[0] < nums[n - 1]) || cnt > 1){
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {3, 4, 5, 1, 2};
    bool result = sol.check(nums);
    if(result){
        cout << "The array is sorted and rotated." << endl;
    } else {
        cout << "The array is not sorted and rotated." << endl;
    }
}