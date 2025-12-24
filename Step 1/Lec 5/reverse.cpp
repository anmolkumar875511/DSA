#include<iostream>
#include<vector>
using namespace std;

void reverseV(vector<int>& v, int i){
	if(i >= (int)v.size()/2) return;
	swap(v[i], v[v.size() - i - 1]);
	reverseV(v, i + 1);
}

int main(){
	int n;
	cout << "Enter size: ";
	cin >> n;
	vector<int> v;
	cout << "Enter elements of vector: ";
	int m;
	for(int i = 0; i < n; i++){
		cin >> m;
		v.push_back(m);
	}

	reverseV(v, 0);

	cout << "Reversed vector: ";
	for(int i = 0; i < n; i++){
		cout << v[i] << " ";
	}
	cout << endl;
	return 0;
}
