#include<iostream>
using namespace std;

void printTillN(int n){
	if(n < 1) return;
	printTillN(n-1);
	cout << n << " ";
}

int main(){
	int n;
	cout << "Enter a number: ";
	cin >> n;
	printTillN(n);
	cout << endl;
}
