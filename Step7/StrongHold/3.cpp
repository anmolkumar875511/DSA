#include<iostream>
using namespace std;

class Solution {
public:
    long long MOD = 1000000007LL;

    long long power(long long base, long long exp) {
        if(exp == 0) return 1;
        
        long long half = power(base, exp / 2);

        long long res = (half * half) % MOD;
        
        if(exp % 2 == 1) {
            res = (res * base) % MOD;
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        long long evens = (n + 1) / 2;
        long long odds = n / 2;

        long long evenM = power(5, evens);
        long long oddM = power(4, odds);

        return (int)((evenM * oddM) % MOD);
    }
};


int main() {
    Solution sol;
    long long n = 50;
    cout << sol.countGoodNumbers(n) << endl; // Output: 564908303
    return 0;
}
