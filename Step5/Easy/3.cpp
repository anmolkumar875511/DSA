#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size() - 1;
        for(int i = n; i >= 0; i--) {
            if((num[i] - '0') & 1) {
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};


int main() {
    Solution sol;
    string num = "35427";
    cout << sol.largestOddNumber(num) << endl; // Output: "35427"
    return 0;
}