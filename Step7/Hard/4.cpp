#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    void f(int i, int j, string& s, vector<vector<int>>& maze, vector<string>& ans) {
        int n = maze.size();
        if(i < 0 || i == n || j < 0 || j == n || maze[i][j] == 0) {
            return;
        }
        if(i == n - 1 && j == n - 1) {
            ans.push_back(s);
            return;
        }
        
        maze[i][j] = 0;
        
        s.push_back('D');
        f(i + 1, j, s, maze, ans);
        s.pop_back();
        
        s.push_back('L');
        f(i, j - 1, s, maze, ans);
        s.pop_back();
        
        s.push_back('R');
        f(i, j + 1, s, maze, ans);
        s.pop_back();
        
        s.push_back('U');
        f(i - 1, j, s, maze, ans);
        s.pop_back();
        
        maze[i][j] = 1;
    }
public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        string s = "";
        vector<string> ans;
        int n = maze.size();
        if(maze[0][0] == 0 ||maze[n - 1][n - 1] == 0) {
            return ans;
        }
        f(0, 0, s, maze, ans);
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<int>> maze = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<string> ans = s.ratInMaze(maze);
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}