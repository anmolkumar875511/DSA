#include<iostream>
#include<climits>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        bool sign = (dividend >= 0) == (divisor >= 0);

        long n = labs((long)dividend);
        long d = labs((long)divisor);
        long ans = 0;

        while (n >= d) {
            int cnt = 0;
            while (n >= (d << (cnt + 1))) {
                cnt++;
            }
            ans += (1L << cnt);
            n -= (d << cnt);
        }

        ans = sign ? ans : -ans;

        if (ans > INT_MAX) return INT_MAX;
        if (ans < INT_MIN) return INT_MIN;

        return ans;
    }
};

int main() {
    Solution sol;
    int dividend = 10;
    int divisor = 3;
    int ans = sol.divide(dividend, divisor);
    cout << ans << endl;
    return 0;
}