#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size();
        int sum = 0;
        for(int num : arr) {
            sum += num;
        }
        int target = sum - diff;
        if(target < 0 || (target & 1)) {
            return 0;
        }
        int k = target / 2;
        vector<int> curr(k + 1, 0), prev(k + 1, 0);
        curr[0] = prev[0] = 1;
        if(arr[0] <= k) {
            prev[arr[0]]++;
        }
        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= k; j++) {
                int not_take = prev[j];
                int take = 0;
                if(arr[i] <= j) {
                    take = prev[j - arr[i]];
                }
                curr[j] = take + not_take;
            }
            prev = curr;
        }
        return prev[k];
    }
};


int main() {
    Solution sol;
    vector<int> arr = {1, 5, 11, 5};
    int diff = 6;
    int count = sol.countPartitions(arr, diff);
    cout << "Count of partitions: " << count << endl;
    return 0;
}