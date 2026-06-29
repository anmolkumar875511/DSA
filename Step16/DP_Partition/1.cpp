#include<iostream>
#include<vector>
using namespace std;


class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for(int i = n - 1; i >= 1; i--) {
            for(int j = i + 1; j < n; j++) {
                int minE = 1e9;
                for(int k = i; k < j; k++) {
                    int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                    minE = min(minE, steps);
                }
                dp[i][j] = minE;
            }
        }
        return dp[1][n - 1];
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 4};
    cout << sol.matrixMultiplication(arr);
    return 0;
}