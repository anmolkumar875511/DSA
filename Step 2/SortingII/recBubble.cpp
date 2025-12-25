#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int>& v, int low, int high){
	if(high < 2) return;

	bool notSwapped = true;

	for(int i = low; i < high; i++){
		if(v[i] > v[i + 1]){
			int temp = v[i + 1];
			v[i + 1] = v[i];
			v[i] = temp;
			notSwapped = false;
		}
	}

	if (notSwapped) return;

	bubbleSort(v, low, high - 1);
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

	bubbleSort(v, 0, v.size() - 1);

	cout << "After sorting: ";
	for(int i = 0; i < n; i++){
		cout << v[i] << " ";
	}

	cout << endl;
	return 0;
}

