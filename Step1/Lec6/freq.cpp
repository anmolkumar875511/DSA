#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
	int n;
	cout << "Enter size: ";
	cin >> n;

	unordered_map<int, int> freq;
	int m;
	cout << "Enter elements: ";
	for(int i = 0; i < n; i++){
		cin >> m;
		freq[m]++;
	}

	for(auto& x : freq){
		cout << x.first << ": " << x.second << endl;
	}

	return 0;
}	
