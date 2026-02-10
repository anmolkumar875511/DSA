#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string minWindow(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        int minLen = n1 + 1, bestStart = -1;

        for(int i = 0; i < n1; i++) {
            int j = 0;

            while(i < n1) {
                if (s1[i] == s2[j]) j++;
                if (j == n2) break;
                i++;
            }

            if (i >= n1) break;

            int end = i;
            j = n2 - 1;
            while(j >= 0) {
                if (s1[i] == s2[j]) j--;
                if (j < 0) break;
                i--;
            }

            int currentLen = end - i + 1;
            if (currentLen < minLen) {
                minLen = currentLen;
                bestStart = i;
            }
        }

        return (bestStart == -1) ? "" : s1.substr(bestStart, minLen);
    }
};


int main() {
    Solution obj;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << obj.minWindow(s, t) << endl;
    return 0;
}