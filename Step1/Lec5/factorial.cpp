#include<iostream>
using namespace std;

int factorial(int n){
	if(n < 2) return 1;
	return n * factorial(n - 1);
}

int main(){
	int n;
	cout << "Enter a interger: ";
	cin >> n;
	cout << "Factorial of " << n << ": " << factorial(n) << endl;
}
