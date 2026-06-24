#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int> curr(m + 1, 0), prev(m + 1, 0);
        for(int i = 0; i <= m; i++) {
            prev[i] = i;
        }
        for(int i = 0; i < n; i++) {
            curr[0] = i + 1;
            for(int j = 0; j < m; j++) {
                if(word1[i] == word2[j]) {
                    curr[j + 1] = prev[j];
                }
                else {
                    curr[j + 1] = 1 + min({prev[j], prev[j + 1], curr[j]});
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};

int main() {
    Solution s;
    string word1 = "horse", word2 = "ros";
    cout << s.minDistance(word1, word2) << endl;
    return 0;
}