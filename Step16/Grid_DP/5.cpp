#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> curr(n, 0), prev(n, 0);
        prev[0] = triangle[0][0];
        for(int i = 1; i < n; i++) {
            curr[0] = prev[0] + triangle[i][0];
            for(int j = 1; j < i; j++) {
                curr[j] = min(prev[j], prev[j - 1]) + triangle[i][j];
            }
            curr[i] = prev[i - 1] + triangle[i][i];
            prev = curr;
        }
        int minE = 1e7;
        for(int num : prev) {
            minE = min(minE, num);
        }
        return minE;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
    cout << sol.minimumTotal(triangle) << endl;
    return 0;
}