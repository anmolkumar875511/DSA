#include<iostream>
#include<bitset>
#include<string>
#include<cmath>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> output;
        for (int i = pow(2, n); i < pow(2, n + 1); ++i) {
            string bitmask = bitset<32>(i).to_string().substr(32 - n);
            vector<int> curr;
            for (int j = 0; j < n; ++j) {
                if (bitmask[j] == '1') {
                    curr.push_back(nums[j]);
                }
            }
            output.push_back(curr);
        }
        return output;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> output = sol.subsets(nums);
    for (int i = 0; i < output.size(); ++i) {
        for (int j = 0; j < output[i].size(); ++j) {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}