#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> curr(target + 1, 0), prev(target + 1, 0);
        prev[0] = curr[0] = 1;
        if(arr[0] <= target) {
            prev[arr[0]]++;
        }
        
        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= target; j++) {
                int not_take = prev[j];
                int take = 0;
                if(arr[i] <= j) {
                    take = prev[j - arr[i]];
                }
                curr[j] = take + not_take;
            }
            prev = curr;
        }
        return prev[target];
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 1, 2};
    int target = 4;
    int count = sol.perfectSum(arr, target);
    cout << "Count of perfect sums: " << count << endl;
    return 0;
}