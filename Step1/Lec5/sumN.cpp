#include<iostream>
using namespace std;

int sumN(int n){
	if(n < 1) return 0;
	return n + sumN(n - 1);
}

int main(){
	int n;
	cout << "Enter a integer: ";
	cin >> n;
	cout << "Sum for 1 to " << n << ": " << sumN(n) << endl;
}
