#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
  public:
    int countSubstring(string s) {
        int lastA = -1;
        int lastB = -1;
        int lastC = -1;
        int count = 0;
        
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'a') {
                lastA = i;
            }
            else if(s[i] == 'b') {
                lastB = i;
            }
            else {
                lastC = i;
            }
            count += min({lastA, lastB, lastC}) + 1;
        }
        return count;
    }
};


int main() {
    Solution sol;
    string s = "abcabc";
    int result = sol.countSubstring(s);
    cout << "Count of substrings containing 'a', 'b', and 'c': " << result << endl;
    return 0;
}