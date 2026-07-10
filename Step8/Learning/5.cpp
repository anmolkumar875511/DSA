#include<iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(int n) {
        int cnt = 0;
        while(n > 0) {
            cnt += (n  & 1);
            n = n >> 1;
        }
        return cnt;
    }
};

int main() {
    Solution sol;
    int n = 5; // Example input
    int result = sol.hammingWeight(n);
    cout << "Hamming weight of " << n << " is " << result << endl;
    return 0;
}