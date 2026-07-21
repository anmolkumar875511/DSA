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

public:
    vector<int> rabinKarp(string text, string pattern) {
        int n = text.size();
        int m_len = pattern.size();
        
        if (m_len > n || m_len == 0) return {};

        long long p = 31;
        long long mod = 1e9 + 7;
        vector<int> matches;

        auto [hashP, pPow] = findHash(pattern, m_len, p, mod);
        auto [hashT, _] = findHash(text, m_len, p, mod);

        for (int i = 0; i <= n - m_len; i++) {
            if (hashT == hashP) {
                if (text.substr(i, m_len) == pattern) {
                    matches.push_back(i);
                }
            }

            long long leadingChar = (text[i] - 'a' + 1) * pPow % mod;
            hashT = (hashT - leadingChar + mod) % mod;
            hashT = (hashT * p + (text[i + m_len] - 'a' + 1)) % mod;
        }

        return matches;
    }
};