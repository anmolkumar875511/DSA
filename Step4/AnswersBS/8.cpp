#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
  public:
    bool canPlace(vector<int> stalls, int dist, int cows) {
        int lastCowPos = stalls[0];
        int cowCounter = 1;
        int n = stalls.size();
        
        for(int i = 1; i < n; i++) {
            if(stalls[i] - lastCowPos >= dist) {
                lastCowPos = stalls[i];
                cowCounter++;
            }
            if(cowCounter >= cows) {
                return true;
            }
        }
        return cowCounter >= cows;
    } 


    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());
        
        int low = 1;
        int high = stalls.back() - stalls.front();
        
        int ans = 1;
        
        while(low <= high) {
            int mid = low + ((high - low) / 2);
            
            if(canPlace(stalls, mid, k)) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> stalls = {1, 2, 8, 4, 9}; // Example input for stalls
    int k = 3; // Example input for number of cows
    int result = sol.aggressiveCows(stalls, k);
    cout << "Largest minimum distance: " << result << endl;
    return 0;
}