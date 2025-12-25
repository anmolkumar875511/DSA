#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int r = 0;
        while(x != 0){
            int last = x % 10;
            x = x / 10;

            if (r > INT_MAX / 10 || (r == INT_MAX / 10 && last > 7)) return 0;
            if (r < INT_MIN / 10 || (r == INT_MIN / 10 && last < -8)) return 0;

            r = r * 10 + last;
        }
        return r;
    }
};

int main() {
    Solution sol;
    int x = -123;
    int reversed = sol.reverse(x);
    cout << "Original: " << x << ", Reversed: " << reversed << endl;
    return 0;
}