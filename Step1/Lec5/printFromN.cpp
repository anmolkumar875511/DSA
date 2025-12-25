#include<iostream>
using namespace std;

void printFromN(int n){
	if(n < 1) return;
	cout << n << " ";
	printFromN(n-1);
}

int main(){
	int n;
	cout << "Enter a number: ";
	cin >> n;
	printFromN(n);
	cout << endl;
}
