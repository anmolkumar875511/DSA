#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;

        sort(intervals.begin(), intervals.end(),
        [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int cnt = 0;
        int last_end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < last_end) {
                cnt++;
            } else {
                last_end = intervals[i][1];
            }
        }
        return cnt;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    cout << sol.eraseOverlapIntervals(intervals) << endl; // Output: 1
    return 0;
}
