#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        int top = 0;
        int down = n - 1;
        while(top < down) {
            if(mat[top][down]) top++;
            else if(mat[down][top]) down--;
            else {
                top++;
                down--;
            }
        }
        if(top > down) return -1;
        for(int i = 0; i < n; i++) {
            if((i != top && mat[top][i]) || (!mat[i][top])) return -1;
        }
        return top;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {{0, 0, 1}, {0, 1, 0}, {1, 0, 0}};
    int result = sol.celebrity(mat);
    cout << "Celebrity: " << result << endl;
    return 0;
}