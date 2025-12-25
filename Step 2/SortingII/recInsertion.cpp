#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int>& v, int low, int high){

	if(low >= high) return;

	insertionSort(v, low, high - 1);
	int j = high - 1, key = v[high];

	while(j >= low && v[j] > key){
		v[j + 1] = v[j];
		j--;
	}

	v[j + 1] = key;
}


int main(){
	int n;
	cout << "Enter size: ";
	cin >> n;

	vector<int> v;
	int m;
	cout << "Enter elements: ";
	for(int i = 0; i < n; i++){
		cin >> m;
		v.push_back(m);
	}

	insertionSort(v, 0, v.size() - 1);

	cout << "After sorting: ";
	for(int i = 0; i < n; i++){
		cout << v[i] << " ";
	}

	cout << endl;
	return 0;
}

