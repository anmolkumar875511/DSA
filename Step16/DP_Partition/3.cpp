#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(m + 2, vector<int> (m + 2, 0));
        for(int i = m; i >= 1; i--) {
            for(int j = i; j <= m; j++) {
                int minE = 1e9;
                for(int k = i; k <= j; k++) {
                    int cost = cuts[j + 1] - cuts[i - 1] + dp[i][k - 1] + dp[k + 1][j];
                    minE = min(minE, cost);
                }
                dp[i][j] = minE;
            }
        }
        return dp[1][m];
    }
};

int main() {
    Solution sol;
    vector<int> cuts = {1, 3, 4, 5};
    cout << sol.minCost(5, cuts) << endl;
    return 0;
}