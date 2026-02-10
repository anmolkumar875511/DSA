#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;
        for(int i = 0; i < k; i++) {
            sum += cardPoints[i];
        }
        int max_sum = sum;
        for(int i = 0; i < k; i++) {
            sum -= cardPoints[k-i-1];
            sum += cardPoints[n-i-1];
            max_sum = max(max_sum, sum);
        }
        return max_sum;
    }
};


int main() {
    Solution sol;
    vector<int> cardPoints = {1,2,3,4,5,6,1};
    int k = 3;
    cout << sol.maxScore(cardPoints, k) << endl; // Output: 12
    return 0;
}