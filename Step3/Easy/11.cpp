#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int n = nums.size();
        int cnt = 0;
        int maxCnt = 0;

        for(int num : nums) {
            if(num != 1){
                cnt = 0;
            }
            else{
                cnt++;
                maxCnt = max(maxCnt, cnt);
            }
        }
        return maxCnt;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    int maxConsecutiveOnes = sol.findMaxConsecutiveOnes(nums);
    cout << "The maximum number of consecutive 1s is: " << maxConsecutiveOnes << endl;
    return 0;
}