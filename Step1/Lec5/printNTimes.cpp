#include<iostream>
using namespace std;

void printNTimes(int n){
	if(n < 1) return;
	cout << "Anmol Kumar Shaharwal" << endl;
	printNTimes(n-1);
}

int main(){
	int n;
	cout << "Enter a integer: ";
	cin >> n;
	printNTimes(n);
	return 0;
}
