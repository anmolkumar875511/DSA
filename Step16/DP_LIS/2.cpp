#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> getLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1), hash(n , 0);
        int max_len = 1;
        int last_idx = 0;
        for(int i = 0; i < n; i++) {
            hash[i] = i;
            for(int j = 0; j < i; j++) {
                if(arr[j] < arr[i] && dp[i] < 1 + dp[j]) {
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }
            if(max_len < dp[i]) {
                max_len = dp[i];
                last_idx = i;
            }
        }
        vector<int> ans(max_len);
        int i = 0;
        while(hash[last_idx] != last_idx) {
            ans[i] = arr[last_idx];
            last_idx = hash[last_idx];
            i++;
        }
        ans[i] = arr[last_idx];
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


int main() {
    Solution sol;
    vector<int> arr = {10,9,2,5,3,7,101,18};
    vector<int> ans = sol.getLIS(arr);
    for(int i : ans) {
        cout << i << " ";
    }
    return 0;
}