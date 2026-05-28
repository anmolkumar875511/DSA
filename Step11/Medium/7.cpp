#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        priority_queue<int, vector<int>, greater<int>> pq(hand.begin(), hand.end());
        while(!pq.empty()) {
            int curr = pq.top();
            int cycle = groupSize;
            vector<int> store;
            while(cycle && !pq.empty()) {
                if(pq.top() == curr) {
                    curr++;
                    cycle--;
                }
                else if(pq.top() < curr) store.push_back(pq.top());
                else return false;
                pq.pop();
            }
            if(cycle) return false;
            for(int &x : store) pq.push(x);
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 6, 2, 3, 4, 7, 8};
    cout << (sol.isNStraightHand(arr, 3) ? "true" : "false") << endl; // Output: true
    return 0;
}