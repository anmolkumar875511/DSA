#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int> (k + 1, 0)), front(2, vector<int> (k + 1, 0));
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j < 2; j++) {
                for(int m = 1; m < k + 1; m++) {
                    if(j == 1) {
                        curr[j][m] = max(front[0][m] - prices[i], front[1][m]);
                    }
                    else {
                        curr[j][m] = max(front[1][m - 1] + prices[i], front[0][m]);
                    }
                }
            }
            front = curr;
        }
        return front[1][k];
    }
};

int main() {
    Solution s;
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    s.maxProfit(2, prices);
    return 0;
}