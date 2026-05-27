#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
  public:
    vector<int> sortKsortedArray(vector<int> &nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int i = 0; i < k; i++) {
            minHeap.push(nums[i]);
        }
        for (int i = k; i < nums.size(); i++) {
            nums[i - k] = minHeap.top();
            minHeap.pop();
            minHeap.push(nums[i]);
        }
        for (int i = 0; i < k; i++) {
            nums[nums.size() - k + i] = minHeap.top();
            minHeap.pop();
        }
        return nums;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    vector<int> result = sol.sortKsortedArray(nums, k);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}