#include<iostream>
#include<string>
#include<unordered_map>
#include<climits>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int cnt = 0;
        int j = 0;
        int si = -1;
        int min_len = INT_MAX;
        unordered_map<char, int> freq;
        for(int i = 0; i < m; i++) {
            freq[t[i]]++;
        }
        for(int i  = 0; i < n; i++) {
            if(freq[s[i]] > 0) {
                cnt++;
            }
            freq[s[i]]--;
            while(cnt == t.size()) {
                if(i-j+1 < min_len && cnt == t.size()) {
                    min_len = i-j+1;
                    si = j;
                }
                freq[s[j]]++;
                if(freq[s[j]] > 0) {
                    cnt--;
                }
                j++;
            }
        }
        if(si == -1) {
            return "";
        }
        return s.substr(si, min_len);
    }
};

int main() {
    Solution obj;
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << obj.minWindow(s, t) << endl;
    return 0;
}
