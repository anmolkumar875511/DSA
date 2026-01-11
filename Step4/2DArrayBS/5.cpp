#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
    int countLessEqual(vector<vector<int>>& mat, int element) {
        int count = 0;
        int row = mat.size();
        
        for(int i = 0; i < row; i++) {
            count = count + upper_bound(mat[i].begin(), mat[i].end(), element) - mat[i].begin();
        }
        
        return count;
    }
    
    int median(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        
        int low = mat[0][0];
        int high = mat[0][col - 1];
        for(int i = 0; i < row; i++) {
            low = min(low, mat[i][0]);
            high = max(high, mat[i][col - 1]);
        }
        
        while(low < high) {
            int mid = low + (high - low) / 2;
            int required = (row * col) / 2 + 1;
            if(countLessEqual(mat, mid) < required) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        return low;
    }
};


int main() {
    vector<vector<int>> mat = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };
    Solution sol;
    int result = sol.median(mat);
    cout << "Median of the matrix is: " << result << endl; // Output: Median of the matrix is: 5
    return 0;
}