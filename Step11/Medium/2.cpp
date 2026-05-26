#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
  public:
    int kthSmallest(vector<int> &nums, int k) {
        priority_queue<int> max_heap(nums.begin(), nums.begin() + k);
        for(int i = k; i < nums.size(); i++) {
            if(nums[i] < max_heap.top()) {
                max_heap.pop();
                max_heap.push(nums[i]);
            }
        }
        return max_heap.top();
    }
};


int main() {
    Solution sol;
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    cout << sol.kthSmallest(nums, k) << endl; // Output: 2
    return 0;
}