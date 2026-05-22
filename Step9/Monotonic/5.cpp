#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if(!height.size()) return 0;
        int n = height.size();
        vector<int> temp(n);
        int ele = height[0];
        for(int i = 0; i < n; i++) {
            if(height[i] > ele) ele = height[i];
            temp[i] = ele;
        }
        cout << endl;
        int ans = 0;
        ele = height[n -1];
        for(int i = n - 1; i >= 0; i--) {
            if(height[i] > ele) ele = height[i];
            ans += min(temp[i], ele) - height[i];
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << sol.trap(height);
    return 0;
}