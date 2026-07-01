#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        for(int i = n - 1; i >= 0; i--) {
            int maxE = 0;
            int max_sum = 0;
            for(int j = i; j < min(n, i + k); j++) {
                maxE = max(maxE, arr[j]);
                int sum = (maxE * (j - i + 1) + dp[j + 1]);
                max_sum = max(max_sum, sum);
            }
            dp[i] = max_sum;
        }
        return dp[0];
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1,15,7,9,2,5,10};
    int k = 3;
    cout << sol.maxSumAfterPartitioning(arr, k) << endl;
    return 0;
}