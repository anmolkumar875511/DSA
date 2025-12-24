#include<iostream>
#include<cmath>
using namespace std;

bool isArmstrongNumber(int n){
    if(n < 0) return false;
    if(n < 10) return true;

    int cnt = (int)log10(n) + 1;
    int sum = 0;
    int tmp = n;

    while(tmp > 0){
        sum = sum + pow((tmp % 10), cnt);
        if(sum > n) return false;
        tmp = tmp / 10;
    }
    return sum == n;
}

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    if(isArmstrongNumber(n)){
        cout << n << " is Armstrong Number." << endl;
    }
    else{
        cout << n << " is not an Armstrong Number." << endl;
    }
}