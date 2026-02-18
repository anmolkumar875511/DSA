#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
    long long solve(vector<int>& bt) {
        int n = bt.size();
        sort(bt.begin(), bt.end());
        long long t = 0;
        long long wt = 0;
        for(int time : bt) {
            wt += t;
            t += (long long)time;
        }
        return wt / (long long) n;
    }
};


int main() {
    Solution sol;
    vector<int> bt = {3, 1, 2};
    cout << sol.solve(bt) << endl; // Output: 1
    return 0;
}