#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        if(k < 0) {
            return 0;
        }
        int n = nums.size();
        int cnt = 0;
        unordered_map<int, int> freq;
        int j = 0;
        for(int i = 0; i < n; i++) {
            freq[nums[i]]++;
            while(freq.size() > k) {
                freq[nums[j]]--;
                if(freq[nums[j]] == 0) {
                    freq.erase(freq.find(nums[j]));
                }
                j++;
            }
            cnt += i-j+1;
        }
        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
};


int main() {
    Solution sol;
    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;
    cout << sol.subarraysWithKDistinct(nums, k) << endl; // Output: 7
    return 0;
}