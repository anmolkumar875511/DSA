// https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/description/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long cnt = prices.size();
        long long cCnt = 1;
        for(int i = 1 ; i < prices.size(); i++){
            if(prices[i] == prices[i - 1] - 1){
                cCnt++;
            }
            else{
                cCnt = 1;
            }
            cnt = cnt + (cCnt - 1);
        }
        return cnt;
    }
};

int main() {
    Solution sol;
    vector<int> prices = {3, 2, 1, 4};
    long long result = sol.getDescentPeriods(prices);
    cout << "Number of smooth descent periods: " << result << endl;
    return 0;
}