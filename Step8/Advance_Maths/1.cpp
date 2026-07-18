#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> primeFac(int n) {
        vector<int> ans;
        for(int i = 2; i * i <= n; i++) {
            if(n % i == 0) {
                ans.push_back(i);
                while(n % i == 0) {
                    n = n / i;
                }
            }
        }
        if(n != 1) {
            ans.push_back(n);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int n = 12;
    vector<int> ans = sol.primeFac(n);
    for(int num : ans) cout << num << " ";
    return 0;
}