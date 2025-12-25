#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        string s = to_string(x);

        int left = 0;
        int right = s.length() - 1;

        while (left < right) {
            
            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }
        return true;
    }
};

// class Solution {
// public:
//     bool isPalindrome(int x) {
//         if(x < 0){
//             return false;
//         }
//         int r = 0;
//         int y = x;
//         while(x > 0){
//             int l = x % 10;
//             x = x / 10;

//             if(r > INT_MAX / 10 || (r == INT_MAX / 10 && l > 7)) return false;
//             if(r < INT_MIN / 10 || (r == INT_MIN / 10 && l < -8)) return false;

//             r = r * 10 + l;
//         }
//         return r == y;
//     }
// };

int main() {
    Solution sol;
    int x = 121;
    bool result = sol.isPalindrome(x);
    cout << "Is " << x << " a palindrome? " << (result ? "Yes" : "No") << endl;
    return 0;
}