#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.empty()) return {newInterval};

        int low = 0, high = intervals.size() - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(newInterval[0] > intervals[mid][0]) low = mid + 1;
            else high = mid - 1;
        }

        intervals.insert(intervals.begin()+low, newInterval);

        vector<vector<int>>res;
        for(const auto& interval : intervals) {
            if(res.empty() || res.back()[1] < interval[0]) res.push_back(interval);
            else res.back()[1] = max(res.back()[1], interval[1]);
        }

        return res;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> intervals = {{1, 3}, {6, 9}};
    vector<int> newInterval = {2, 5};
    vector<vector<int>> result = sol.insert(intervals, newInterval);
    
    cout << "Merged Intervals: ";
    for(const auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}