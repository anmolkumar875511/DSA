#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {

        stack<int> st;
        int n = arr.size();
        const int MOD = 1e9 + 7;
        vector<int> NSE(n, n), PSEE(n , -1);

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            if(!st.empty()) NSE[i] = st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            if(!st.empty()) PSEE[i] = st.top();
            st.push(i);
        }

        long long ans = 0;
        for(int i = 0; i < n; i++) {
            long long leftCount = i - PSEE[i];
            long long rightCount = NSE[i] - i;
            ans = (ans + (arr[i] * leftCount * rightCount) % MOD) % MOD;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {3,1,2,4};
    cout << sol.sumSubarrayMins(arr);
    return 0;
}