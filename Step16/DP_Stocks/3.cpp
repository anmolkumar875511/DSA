#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int> (3, 0)), front(2, vector<int> (3, 0));
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j < 2; j++) {
                for(int k = 1; k < 3; k++) {
                    if(j == 1) {
                        curr[j][k] = max(front[0][k] - prices[i], front[1][k]);
                    }
                    else {
                        curr[j][k] = max(front[1][k - 1] + prices[i], front[0][k]);
                    }
                }
            }
            front = curr;
        }
        return front[1][2];
    }
};

int main() {
    Solution s;
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    cout << s.maxProfit(prices);
    return 0;
}