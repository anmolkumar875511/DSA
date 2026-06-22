#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<unsigned long long> prev(amount + 1, 0), curr(amount + 1, 0);
        for(int i = 0; i <= amount; i++) {
            prev[i] = (i % coins[0] == 0);
        }

        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= amount; j++) {
                unsigned long long not_take = prev[j];
                unsigned long long take = 0LL;
                if(coins[i] <= j) {
                    take = curr[j - coins[i]];
                }
                curr[j] = take + not_take;
            }
            prev = curr;
        }
        return prev[amount];
    }
};

int main() {
    Solution sol;
    int amount = 5;
    vector<int> coins = {1, 2, 5};
    int ans = sol.change(amount, coins);
    cout << ans << endl;
    return 0;
}