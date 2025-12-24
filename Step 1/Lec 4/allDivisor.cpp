#include<iostream>
#include<vector>
using namespace std;

vector<int> allDivisors(int n){
	vector<int> res;

	for(int i = 1; i * i <= n; i++){
		if(n % i == 0){
			res.push_back(i);
			if( n/i != i){
				res.push_back(n/i);
			}
		}
	}
	return res;
}


int main(){

	int n;
	cout << "Enter a integer: ";
	cin >> n;

	vector<int> r = allDivisors(n);

	for(int i : r){
		cout << i << " ";
	}

	cout << endl;
	return 0;
}
	
