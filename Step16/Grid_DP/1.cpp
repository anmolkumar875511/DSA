#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maximumPoints(vector<vector<int>>& mat) {
        int a = mat[0][0];
        int b = mat[0][1];
        int c = mat[0][2];

        for (int i = 1; i < mat.size(); i++) {
            int na = mat[i][0] + max(b, c);
            int nb = mat[i][1] + max(a, c);
            int nc = mat[i][2] + max(a, b);

            a = na;
            b = nb;
            c = nc;
        }

        return max({a, b, c});
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    int ans = sol.maximumPoints(mat);
    cout << ans << endl;
    return 0;
}