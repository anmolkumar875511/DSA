#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int kDistinctChar(string& s, int k) {
        int n = s.size();
        int max_len = 0;
        unordered_map<char, int> freq;
        int j = 0;
        for(int i = 0; i < n; i++) {
            freq[s[i]]++;
            while(freq.size() > k) {
                freq[s[j]]--;
                if(freq[s[j]] == 0) {
                    freq.erase(freq.find(s[j]));
                }
                j++;
            }
            max_len = max(max_len, i-j+1);
        }
        if(freq.size() < k) {
            return -1;
        }
        return max_len;
    }
};

int main() {
    Solution sol;
    string s = "abc";
    int k = 2;
    cout << sol.kDistinctChar(s, k) << endl;
    return 0;
}