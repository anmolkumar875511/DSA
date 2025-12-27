#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(){
    string s = "abc";
    s.push_back('d');
    reverse(s.begin(), s.end());
    cout << s << "\n";
    return 0;
}