#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    void helper(vector<int>& nums, int i, int sum, vector<int>& a) {
      if(i == nums.size()) {
        a.push_back(sum);
        return;
      }
      helper(nums, i+1, sum+nums[i], a);
      helper(nums, i+1, sum, a);
    }
    vector<int> subsetSums(vector<int>& nums) {
        vector<int> a;
        helper(nums, 0, 0, a);
        return a;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<int> result = sol.subsetSums(nums);
    
    cout << "Subset sums: ";
    for (int sum : result) {
        cout << sum << " ";
    }
    cout << endl;
    
    return 0;
}