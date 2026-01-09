#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
  public:
    bool canPlaced(vector<int>& stations, double dist, int number) {
        int n = stations.size();
        int needed = 0;
        for(int i = 1; i < n; i++) {
            double gap = stations[i] - stations[i - 1];
            needed = needed + (int)ceil(gap / dist) - 1;
            if(needed > number) {
                return false;
            }
        }
        return true;
    }
    
    double minMaxDist(vector<int>& stations, int K) {
        // Code here
        int n = stations.size();
        double low = 0.0;
        double high = 0.0;
        for(int i = 1; i < n; i++) {
            high = max(high, (double)(stations[i] - stations[i - 1]));
        }
        
        while(high - low > 1e-7) {
            double mid = (low + high) / 2.0;
            if(canPlaced(stations, mid, K)) {
                high = mid;
            }
            else {
                low = mid;
            }
        }
        return round(high * 1e6) / 1e6;
    }
};


int main() {
    Solution sol;
    vector<int> stations = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int K = 9;
    cout << sol.minMaxDist(stations, K) << endl;
    return 0;
}