#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int front_0 = 0, front_1 = 0;
        int curr_0 = 0, curr_1 = 0;
        for(int i = prices.size() - 1; i >= 0; i--) {
            curr_0 = max(front_1 + prices[i] - fee, front_0);
            curr_1 = max(front_0 - prices[i], front_1);
            front_0 = curr_0;
            front_1 = curr_1;
        }
        return front_1;
    }
};

int main() {
    Solution sol;
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    cout << sol.maxProfit(prices, fee);
    return 0;
}
