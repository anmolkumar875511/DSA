#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        long long weight = 0;
        double ans = 0.0;
        vector<pair<double, long long>> val_per_wt;

        for(int i = 0; i < n; i++) {
            val_per_wt.emplace_back((double)val[i]/wt[i], wt[i]);
        }

        sort(val_per_wt.rbegin(), val_per_wt.rend());

        for(int i = 0; i < n && weight < capacity; i++) {
            long long measure = min(capacity - weight, val_per_wt[i].second);
            weight += measure;
            ans += val_per_wt[i].first * measure;
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int capacity = 50;
    cout << sol.fractionalKnapsack(val, wt, capacity) << endl; // Output: 240.0
    return 0;
}