#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void func(int col, int n, vector<string>& v, vector<vector<string>>& ans, vector<bool>& rows, vector<bool>& dia1, vector<bool>& dia2) {
        if(col == n) {
            ans.push_back(v);
        }
        for(int i = 0; i < n; i++) {
            if(rows[i] == false && dia1[col + i] == false && dia2[n - col + i - 1] == false) {
                v[i][col] = 'Q';
                rows[i] = true;
                dia1[col + i] = true;
                dia2[n - col + i - 1] = true;

                func(col + 1, n, v, ans, rows, dia1, dia2);

                v[i][col] = '.';
                rows[i] = false;
                dia1[col + i] = false;
                dia2[n - col + i - 1] = false;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> v(n, string(n, '.'));
        vector<vector<string>> ans;
        
        vector<bool> rows(n, false);
        vector<bool> dia1(2 * n - 1, false);
        vector<bool> dia2(2 * n - 1, false);
        func(0, n, v, ans, rows, dia1, dia2);
        return ans;
    }
};

int main() {
    Solution s;
    vector<vector<string>> ans = s.solveNQueens(4);
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}