#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if(n < 3) {
            return 0;
        }
        vector<bool> sieve(n, true);
        sieve[0] = false;
        sieve[1] = false;
        for(int i = 2; i < n; i++) {
            if(sieve[i] == false) {
                continue;
            }
            for(long j = 1L * i * i; j < n; j += i) {
                sieve[j] = false;
            }
        }
        int cnt = 0;
        for(bool f : sieve) {
            cnt += f;
        }
        return cnt;
    }
};

int main() {
    Solution s;
    cout << s.countPrimes(10) << endl;
    return 0;
}