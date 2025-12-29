#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
  public:
    int maxLen(vector<int>& arr) {

        int n = arr.size();
        unordered_map<int, int> preMapSum;
        int sum = 0;
        int maxLength = 0;

        for(int i = 0; i < n; i++) {
          sum = sum + arr[i];

          if(sum == 0) {
            maxLength = max(maxLength, i + 1);
          }

          if(preMapSum.find(sum) != preMapSum.end()) {
            maxLength = max(maxLength, i - preMapSum[sum]);
          }

          else {
            preMapSum[sum] = i;
          }
        }
        return maxLength;
    }
};


int main() {
    Solution sol;
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10, 23}; // Example input
    int result = sol.maxLen(arr);
    cout << "Length of the longest subarray with sum 0: " << result << endl;
    return 0;
}