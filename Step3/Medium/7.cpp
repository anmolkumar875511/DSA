#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        vector<int> ans(nums.size(), 0);
        int pos = 0;
        int neg = 1;

        for(int num : nums) {
            if(num < 0) {
                ans[neg] = num;
                neg = neg + 2;
            }
            else{
                ans[pos] = num;
                pos = pos + 2;
            }
        }

        return ans;
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
    vector<int> result = sol.rearrangeArray(nums);

    cout << "Rearranged Array: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}