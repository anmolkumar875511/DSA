#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        priority_queue<pair<int, int>> pq;
        for(int num : nums) freq[num]++;
        for(auto const [num, count] : freq) {
            pq.push({count, num});
        }
        vector<int> a(k);
        for(int i = 0; i < k; i++) {
            a[i] = pq.top().second;
            pq.pop();
        }
        return a;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> result = sol.topKFrequent(nums, k);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
