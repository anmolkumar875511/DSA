#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
private:
    pair<long long, long long> findHash(const string& s, int len, long long p, long long m) {
        long long hashValue = 0;
        long long pPow = 1;

        for (int i = 0; i < len; i++) {
            hashValue = (hashValue * p + (s[i] - 'a' + 1)) % m;
            if (i < len - 1) {
                pPow = (pPow * p) % m;
            }
        }
        return {hashValue, pPow};
    }

    int rabinKarp(const string& text, const string& pattern) {
        int n = text.size();
        int m_len = pattern.size();
        
        if (m_len > n || m_len == 0) return -1;

        long long p = 31;
        long long mod = 1e9 + 7;
        int matches = 0;

        auto [hashP, pPow] = findHash(pattern, m_len, p, mod);
        auto [hashT, _] = findHash(text, m_len, p, mod);

        for (int i = 0; i <= n - m_len; i++) {
            if (hashT == hashP) {
                if (text.substr(i, m_len) == pattern) {
                    matches++;
                }
            }

            if (i < n - m_len) {
                long long leadingChar = (text[i] - 'a' + 1) * pPow % mod;
                hashT = (hashT - leadingChar + mod) % mod;
                hashT = (hashT * p + (text[i + m_len] - 'a' + 1)) % mod;
            }
        }

        return matches == 0 ? -1 : matches;
    }

public:
    int repeatedStringMatch(string a, string b) {
        if (a == b) {
            return 1;
        }
        string source = a;
        int cnt = 1;
        while (source.size() < b.size()) {
            source += a;
            cnt++;
        }
        
        if (rabinKarp(source, b) != -1) {
            return cnt;
        }
        if (rabinKarp(source + a, b) != -1) {
            return cnt + 1;
        }
        return -1;
    }
};

int main() {
    Solution sol;
    string a = "abcd";
    string b = "cdabcdab";
    cout << sol.repeatedStringMatch(a, b);
    return 0;
}