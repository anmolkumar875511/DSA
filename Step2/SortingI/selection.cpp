#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int>& v){

	for(int i = 0; i < v.size() - 1; i++){

		int minI = i;

		for(int j = i + 1; j < v.size(); j++){
			if(v[j] < v[minI]){
				minI = j;
			}
		}
		
		if(i != minI){
			int temp = v[minI];
			v[minI] = v[i];
			v[i] = temp;
		}
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

	selectionSort(v);

	cout << "After sorting: ";
	for(int i = 0; i < n; i++){
		cout << v[i] << " ";
	}

	cout << endl;
	return 0;
}
