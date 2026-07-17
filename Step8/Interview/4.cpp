#include<iostream>
using namespace std;

class Solution {
private:
    int xor_to(int n) {
        if(n % 4 == 0) {
            return n;
        }
        if(n % 4 == 1) {
            return 1;
        }
        if(n % 4 == 2) {
            return n + 1;
        }
        return 0;
    }
public:
    int findXOR(int l, int r) {
        return xor_to(l - 1) ^ xor_to(r);
    }
};

int main() {
    Solution sol;
    int l = 3;
    int r = 5;
    cout << sol.findXOR(l, r);
    return 0;
}