#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int sRow = 0, eRow = m - 1;
        int sCol = 0, eCol = n - 1;
        vector<int> res;

        while(sRow <= eRow && sCol <= eCol) {

            for(int j = sCol; j <= eCol; j++) res.push_back(matrix[sRow][j]);
            sRow++;

            for(int j = sRow; j <= eRow; j++) res.push_back(matrix[j][eCol]);
            eCol--;

            if(sRow <= eRow) {
                for(int j = eCol; j >= sCol; j--) res.push_back(matrix[eRow][j]);
                eRow--;
            }

            if(sCol <= eCol) {
                for(int j = eRow; j >= sRow; j--) res.push_back(matrix[j][sCol]);
                sCol++;
            }

        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> result = sol.spiralOrder(matrix);

    cout << "Spiral Order: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}