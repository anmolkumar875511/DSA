#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    vector<int> leaders(vector<int>& nums) {

        int n  = nums.size();
        int maxE = INT_MIN;
        vector<int> leaders;

        for(int i = n - 1; i > -1; i--) {
            if(nums[i] > maxE) {
                leaders.insert(leaders.begin(), nums[i]);
                maxE = nums[i];
            }
        }

        return leaders;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {16, 17, 4, 3, 5, 2};
    vector<int> result = sol.leaders(nums);

    cout << "Leaders in the array: ";
    for(int leader : result) {
        cout << leader << " ";
    }
    cout << endl;

    return 0;
}