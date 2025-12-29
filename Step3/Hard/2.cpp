#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1 = INT_MIN, ele2 = INT_MIN;
        int cnt1 = 0, cnt2 = 0;
        for(int num : nums) {
            if(cnt1 == 0 && num != ele2) {
                cnt1++;
                ele1 = num;
            }
            else if(cnt2 == 0 && num != ele1) {
                cnt2++;
                ele2 = num;
            }
            else if(ele1 == num) {
                cnt1++;
            }
            else if(ele2 == num) {
                cnt2++;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0;
        cnt2 = 0;

        for(int num : nums) {
            if(ele1 == num) {
                cnt1++;
            }
            else if(ele2 == num) {
                cnt2++;
            }
        }

        vector<int> ans;
        int n = nums.size() / 3;
        if(cnt1 > n) {
            ans.push_back(ele1);
        }
        if(cnt2 > n) {
            ans.push_back(ele2);
        }
        sort(ans.begin(), ans.end());

        return ans;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {3,2,3}; // Example input
    vector<int> result = sol.majorityElement(nums);
    
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}