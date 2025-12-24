// https://leetcode.com/problems/count-covered-buildings/description/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> maxRow(n+1);
        vector<int> minRow(n+1, n+1);
        vector<int> maxCol(n+1);
        vector<int> minCol(n+1, n+1);

        for(vector<int> v : buildings) {
            int x = v[0], y = v[1];
            maxRow[y] = max(maxRow[y], x);
            minRow[y] = min(minRow[y], x);
            maxCol[x] = max(maxCol[x], y);
            minCol[x] = min(minCol[x], y);
        }

        int cnt = 0;
        for(vector<int> v : buildings){
            int x = v[0], y = v[1];
            if (x > minRow[y] && x < maxRow[y] && y > minCol[x]&& y < maxCol[x]) {
                cnt++;
            }
        }
        return cnt;
    }
};


int main() {
    Solution sol;
    int n = 5;
    vector<vector<int>> buildings = {{1,2}, {2,2}, {3,2}, {2,3}, {2,4}};
    int result = sol.countCoveredBuildings(n, buildings);
    cout << "Number of covered buildings: " << result << endl;
    return 0;
}