#include<iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    long long int minimumCostToConnectSticks(vector<int> &arr) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(int stick : arr) pq.push(1LL * (stick));
        long long ans = 0;
        while(!pq.empty()) {
             int first = pq.top();
             pq.pop();
             if(pq.empty()) break;
             int second = pq.top();
             pq.pop();
             ans += first + second;
             pq.push(first + second);
        }
        return ans;
    }
};


int main() {
    Solution sol;
    vector<int> arr = {2, 4, 3};
    long long ans = sol.minimumCostToConnectSticks(arr);
    cout << ans << endl;
    return 0;
} 