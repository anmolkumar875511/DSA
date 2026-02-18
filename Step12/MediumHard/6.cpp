#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int i = 1;
        int sum = 1;
        while(i < n) {
            if(ratings[i] == ratings[i-1]) {
                sum++;
                i++;
            }
            int peak = 1;
            while(i < n && ratings[i] > ratings[i-1]) {
                peak++;
                sum += peak;
                i++;
            }
            int down = 1;
            while(i < n && ratings[i] < ratings[i-1]) {
                sum += down;
                i++;
                down++;
            }
            if(down > peak) {
                sum += down - peak;
            }
        }
        return sum;
    }
};


int main() {
    Solution sol;
    vector<int> ratings = {1, 0, 2};
    cout << sol.candy(ratings) << endl; // Output: 5
    return 0;
}