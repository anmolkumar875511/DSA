#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    int day(vector<int>& weights, int capacity) {
        int day = 1;
        long long sum = 0;
        for(int weight : weights) {
            if((sum + weight) > capacity) {
                sum = weight;
                day++;
            }
            else {
                sum = sum + weight;
            }
        }
        return day;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = 0;
        int high = 0;
        for(int weight : weights) {
            low = max(low, weight);
            high = high + weight;
        }
        int ans = high;

        while(low <= high) {
            int mid = low + ((high - low) / 2);

            if(day(weights, mid) > days) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }
};


int main() {
    Solution sol;
    vector<int> weights = {1,2,3,4,5,6,7,8,9,10}; // Example input for weights
    int days = 5; // Example input for days
    int result = sol.shipWithinDays(weights, days);
    cout << "Minimum capacity to ship within days: " << result << endl;
    return 0;
}