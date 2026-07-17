#include<iostream>
using namespace std;

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt = 0;
        int XOR = start ^ goal;
        while(XOR) {
            XOR = XOR & (XOR - 1);
            cnt++;
        }
        return cnt;
    }
};

int main() {
    Solution sol;
    int start = 10;
    int goal = 15;
    cout << sol.minBitFlips(start, goal);
    return 0;
}