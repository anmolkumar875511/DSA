#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int>& v){

	int n = v.size();

	for(int i = 1; i < n; i++){

		int key = v[i];
		int j = i - 1;

		while(j > -1 && v[j] > key){
			v[j + 1] = v[j];
			j--;
		}
		v[j + 1] = key;
	}
	return;
}

int main(){
	int n;
	cout << "Enter size: ";
	cin >> n;

	int m;
	vector<int> v;
	cout << "Enter elements: ";
	for(int i = 0; i < n; i++){
		cin >> m;
		v.push_back(m);
	}

	insertionSort(v);

	cout << "After sorting: ";
	for(int i = 0; i < n; i++){
		cout << v[i] << " ";
	}

	cout << endl;
	return 0;
}
