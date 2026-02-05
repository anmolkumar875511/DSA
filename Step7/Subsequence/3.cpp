#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void insert(vector<vector<int>>& v, vector<int> a, vector<int>& nums, int i) {
        if(i < 0) {
            v.push_back(a);
            return;
        }
        insert(v, a, nums, i-1);
        a.push_back(nums[i]);
        insert(v, a, nums, i-1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size() - 1;
        vector<vector<int>> v;
        vector<int> a;
        insert(v, a, nums, n);
        return v;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = sol.subsets(nums);
    
    for (const auto& subset : result) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    return 0;
}