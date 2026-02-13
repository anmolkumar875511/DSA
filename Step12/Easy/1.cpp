#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0, cnt = 0;
        int n = g.size(), m = s.size();
        while(i < n && j < m) {
            if(g[i] <= s[j]) {
                cnt++;
                i++;
                j++;
            }
            else if(g[i] > s[j]) j++;
        }
        return cnt;
    }
};

int main() {
    Solution sol;
    vector<int> g = {1, 2, 3};
    vector<int> s = {1, 1};
    cout << sol.findContentChildren(g, s) << endl; // Output: 1
    return 0;
}