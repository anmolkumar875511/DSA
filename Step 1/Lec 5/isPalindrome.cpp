#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string converter(string s){
        string t = "";
        for(int i = 0; i < s.length(); i++){
            if(s[i] >= 'A' && s[i] <= 'Z'){
                t.push_back(s[i] - 'A' + 'a');
            }
            else if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
                t.push_back(s[i]);
            }
        }
        return t;
    }
    bool isPalindrome(string s) {
        string r = converter(s);
        int left = 0, right = r.length() - 1;
        while(left < right){
            if(r[left] != r[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

int main() {
    Solution sol;
    string s = "0P";
    bool result = sol.isPalindrome(s);
    cout << "Is the string a palindrome? " << (result ? "Yes" : "No") << endl;
    return 0;
}
