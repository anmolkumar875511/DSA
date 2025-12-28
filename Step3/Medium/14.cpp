#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int count = 0;
        int preSum = 0;
        unordered_map<int,int> sumCount;
        sumCount[0] = 1;

        for(int num : nums) {
            preSum = preSum + num;
            int remove = preSum - k;
            if(sumCount.find(remove) != sumCount.end()) {
                count = count + sumCount[remove];
            }
            sumCount[preSum]++;
        }
        return count;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1};
    int k = 2;
    int result = sol.subarraySum(nums, k);

    cout << "Number of subarrays with sum " << k << ": " << result << endl;

    return 0;
}