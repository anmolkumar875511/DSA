#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    long long sumSubarrayMaxs(vector<int>& arr) {

        stack<int> st;
        int n = arr.size();
        vector<int> NGE(n, n), PGEE(n , -1);

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            if(!st.empty()) NGE[i] = st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] < arr[i]) st.pop();
            if(!st.empty()) PGEE[i] = st.top();
            st.push(i);
        }

        long long ans = 0;
        for(int i = 0; i < n; i++) {
            long long leftCount = i - PGEE[i];
            long long rightCount = NGE[i] - i;
            ans = ans + (arr[i] * leftCount * rightCount);
        }
        return ans;
    }

    long long sumSubarrayMins(vector<int>& arr) {

        stack<int> st;
        int n = arr.size();
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
            ans = ans + (arr[i] * leftCount * rightCount);
        }
        return ans;
    }


    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};


int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    cout << sol.subArrayRanges(nums) << endl;
    return 0;
}