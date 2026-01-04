#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    bool canMake(vector<int>& bloomDay, int day, int m, int k) {
        int counter = 0;
        for(int d : bloomDay) {
            if(day >= d) {
                counter++;
            }
            if(day < d) {
                counter = 0;
            }
            if(counter == k) {
                counter = 0;
                m--;
            }
            if(m == 0) {
                return true;
            }
        }
        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if(bloomDay.size() < (long long)m * k) return -1;

        int low = INT_MAX;
        int high = INT_MIN;

        for(int d : bloomDay) {
            low = min(low, d);
            high = max(high, d);
        }

        while(low < high) {
            int mid = low + ((high - low) / 2);
            if(canMake(bloomDay, mid, m, k)) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main() {
    Solution sol;
    vector<int> bloomDay = {1,10,3,10,2}; // Example input for bloomDay
    int m = 3; // Example input for m
    int k = 1; // Example input for k
    int result = sol.minDays(bloomDay, m, k);
    cout << "Minimum days to make bouquets: " << result << endl;
    return 0;
}