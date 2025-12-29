#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i + 1, k = n - 1;
            while(j < k) {
                if(nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                }
                else if(nums[i] + nums[j] + nums[k] < 0) {
                    j++;
                }
                else {
                    res.push_back({nums[i], nums[j], nums[k]});
                    k--;
                    j++;
                    while(j < k && nums[j] == nums[j - 1]) j++;
                    while(j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }
        return res;
    }
};



int main() {
    Solution sol;
    vector<int> nums = {-1,0,1,2,-1,-4}; // Example input
    vector<vector<int>> result = sol.threeSum(nums);
    
    for (const auto& triplet : result) {
        for (int val : triplet) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}