#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        
        for(int i = 0; i < n - 3; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;

            if((long long)nums[i] + nums[i+1] + nums[i+2] + nums[i+3] > target) break;
            if((long long)nums[i] + nums[n-3] + nums[n-2] + nums[n-1] < target) continue;

            for(int j = i + 1; j < n - 2; j++) {
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;

                if((long long)nums[i] + nums[j] + nums[j+1] + nums[j+2] > target) break;
                if((long long)nums[i] + nums[j] + nums[n-2] + nums[n-1] < target) continue;

                int k = j + 1, l = n - 1;
                while(k < l) {
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                    if(sum > target) l--;
                    else if(sum < target) k++;
                    else {
                        res.push_back({nums[i], nums[j], nums[k], nums[l]});
                        do { k++; } while(k < l && nums[k] == nums[k - 1]);
                        do { l--; } while(k < l && nums[l] == nums[l + 1]);
                    }
                }
            }
        }
        return res;
    }
};



int main() {
    Solution sol;
    vector<int> nums = {1, 0, -1, 0, -2, 2}; // Example input
    int target = 0; // Example target
    vector<vector<int>> result = sol.fourSum(nums, target);
    
    for (const auto& quadruplet : result) {
        for (int val : quadruplet) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}