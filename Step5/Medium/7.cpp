#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int beautySum(string s) {
        int sum = 0;
        int n = s.size();

        for(int i = 0; i < n; i++) {
            int freq[26] = {0};

            for(int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                int maxF = 0;
                int minF = 501;

                for(int i = 0; i < 26; i++) {
                    if(freq[i] > 0){
                        maxF = max(maxF, freq[i]);
                        minF = min(minF, freq[i]);
                    }
                }

                sum += (maxF - minF);
            }
        }
        return sum;
    }
};


int main() {
    Solution sol;
    string s = "aabcb";
    int result = sol.beautySum(s);
    cout << "Total beauty sum of all substrings: " << result << endl;
    return 0;
}