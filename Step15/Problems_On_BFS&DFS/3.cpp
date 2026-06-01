#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2)
                    q.push({i, j});
                else if(grid[i][j] == 1)
                    fresh++;
            }
        }

        if(fresh == 0) return 0;

        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {-1, 0, 1, 0};

        int minutes = 0;

        while(!q.empty() && fresh > 0) {
            int sz = q.size();

            for(int i = 0; i < sz; i++) {
                auto [x, y] = q.front();
                q.pop();

                for(int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if(nx < 0 || nx >= m || ny < 0 || ny >= n)
                        continue;

                    if(grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        fresh--;
                        q.push({nx, ny});
                    }
                }
            }

            minutes++;
        }

        return fresh ? -1 : minutes;
    }
};


int main() {
    Solution sol;
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    cout << sol.orangesRotting(grid) << endl;
    return 0;
}