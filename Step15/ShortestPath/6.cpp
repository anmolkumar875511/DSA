#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<int> DIR = {0, -1, 0, 1, 0};
        vector<vector<int>> efforts(n, vector<int> (m, 1e6));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.emplace(0, 0, 0);
        efforts[0][0] = 0;
        while(!pq.empty()) {
            auto [d, r, c] = pq.top();
            pq.pop();

            if(r == n - 1 && c == m - 1 && efforts[r][c] == d) {
                break;
            }
            if(efforts[r][c] < d) {
                continue;
            }

            for(int i = 0; i < 4; i++) {
                int nr = r + DIR[i];
                int nc = c + DIR[i + 1];
                if(nr < 0 || nr == n || nc < 0 || nc == m) continue;
                int diff = max(abs(heights[r][c] - heights[nr][nc]), d);
                if(diff < efforts[nr][nc]) {
                    efforts[nr][nc] = diff;
                    pq.emplace(diff, nr, nc);
                }
            }
        }
        return efforts[n - 1][m - 1];
    }
};


int main() {
    Solution sol;
    vector<vector<int>> heights = {{1,2,2},{3,8,2},{5,3,5}};
    int result = sol.minimumEffortPath(heights);
    cout << "Minimum Effort Path: " << result << endl;
    return 0;
}