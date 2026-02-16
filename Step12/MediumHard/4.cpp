#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());

        int n = arr.size();
        int platforms_needed = 0;
        int max_platforms = 0;
        
        int i = 0, j = 0;

        while (i < n) {
            if (arr[i] <= dep[j]) {
                platforms_needed++;
                i++;
            } else {
                platforms_needed--;
                j++;
            }
            max_platforms = max(max_platforms, platforms_needed);
        }

        return max_platforms;
    }
};


int main() {
    Solution sol;
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};
    cout << sol.minPlatform(arr, dep) << endl; // Output: 3
    return 0;
}