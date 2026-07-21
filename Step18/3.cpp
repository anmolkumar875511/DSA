#include<iostream>
#include<string>
using namespace std;
#define int long long

int findHash(string &s) {
    int n = s.length();

    int p = 31, m = 1e9 + 7;
    int hashVal = 0;

    int pPow = 1;

    for (int i = 0; i < n; ++i) {
        hashVal = (hashVal + (s[i] - 'a' + 1) * pPow) % m;
        pPow = (pPow * p) % m;
    }
    return hashVal;
}

signed main() {
    string s = "abc";
    cout << findHash(s);
    return 0;
}