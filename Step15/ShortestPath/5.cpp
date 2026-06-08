#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> level(n, vector<int> (n, -1));
        queue<pair<int, int>> q;
        vector<int> dr = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> dc = {-1, 0, 1, -1, 1, -1, 0, 1};
        if(grid[0][0] == 0) {
            q.emplace(0, 0);
            level[0][0] = 1;
        }
        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for(int i = 0; i < 8; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr < 0 || nr == n || nc < 0 || nc == n) continue;
                if(grid[nr][nc] == 1 || level[nr][nc] != -1) continue;
                level[nr][nc] = 1 + level[r][c];
                q.emplace(nr, nc);
            }
        }
        return level[n - 1][n - 1];
    }
};


int main() {
    Solution sol;
    vector<vector<int>> grid = {{0,0,0},{1,1,0},{1,1,0}};
    cout << sol.shortestPathBinaryMatrix(grid) << endl;
    return 0;
}