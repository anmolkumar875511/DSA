// https://leetcode.com/problems/count-the-number-of-computer-unlocking-permutations/description/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    static const int MOD = 1000000007;

    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        int first = complexity[0];

        for (int i = 1; i < n; i++) {
            if (complexity[i] <= first)
                return 0;
        }

        long long fact = 1;
        
        for(int i = 2; i < n; i++){
            fact = (fact * i) % MOD;
        }
        return fact;
    }
};

int main() {
    Solution sol;
    vector<int> complexity = {5, 10, 15};
    int result = sol.countPermutations(complexity);
    cout << "Number of unlocking permutations: " << result << endl;
    return 0;
}