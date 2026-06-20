#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<bool> prev(sum + 1, false);
        vector<bool> curr(sum + 1, false);
        prev[0] = curr[0] = true;
        prev[arr[0]] = true;
        for(int i = 1; i < n; i++) {
            for(int j = 1; j <= sum; j++) {
                bool not_take = prev[j];
                bool take = false;
                if(arr[i] <= j) {
                    take = prev[j - arr[i]];
                }
                curr[j] = not_take | take;
            }
            prev = curr;
        }
        return prev[sum];
    }
};

int main() {
    Solution sol;
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    cout << (sol.isSubsetSum(arr, sum) ? "true" : "false") << endl;
    return 0;
}