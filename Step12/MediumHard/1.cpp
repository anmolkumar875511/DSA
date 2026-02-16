#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        vector<pair<int, int>> meetings;
        int n = start.size();
        for(int i = 0; i < n; i++) {
            meetings.emplace_back(end[i], start[i]);
        }
        sort(meetings.begin(), meetings.end());
        int last = -1;
        int cnt = 0;
        for(auto const& meet : meetings) {
            if(meet.second > last) {
                last = meet.first;
                cnt++;
            }
        }
        return cnt;
    }
};

int main() {
    Solution sol;
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};
    cout << sol.maxMeetings(start, end) << endl; // Output: 4
    return 0;
}