#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<int> prev(capacity + 1, 0), curr(capacity + 1, 0);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= capacity; j++) {
                int not_take = prev[j];
                int take = 0;
                if(wt[i] <= j) {
                    take = curr[j - wt[i]] + val[i];
                }
                curr[j] = max(take, not_take);
            }
            prev = curr;
        }
        return *max_element(prev.begin(), prev.end());
    }
};

int main() {
    Solution sol;
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int capacity = 50;
    int ans = sol.knapSack(val, wt, capacity);
    cout << ans << endl;
    return 0;
}