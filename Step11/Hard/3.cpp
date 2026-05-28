#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class KthLargest {
    int num;
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    KthLargest(int k, vector<int>& nums) {
        num = k; 
        for(auto ele : nums) {
            pq.push(ele);
            if(pq.size() > k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > num) pq.pop();
        return pq.top();
    }
};

int main() {
    vector<int> nums = {4, 5, 8, 2};
    KthLargest kthLargest(3, nums);
    cout << kthLargest.add(3) << endl; // Output: 4
    cout << kthLargest.add(5) << endl; // Output: 5
    return 0;
}