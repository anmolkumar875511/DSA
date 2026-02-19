#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        res.push_back(intervals[0]);
        int n = intervals.size();

        for(int i = 1; i < n; i++) {
            if(intervals[i][0] <= res.back()[1]) {
                res.back()[1] = max(intervals[i][1], res.back()[1]);
            }
            else {
                res.push_back(intervals[i]);
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> result = sol.merge(intervals);
    
    cout << "Merged Intervals: ";
    for(const auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}