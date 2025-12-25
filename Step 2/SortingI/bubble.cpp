#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int>& v){
	int end = v.size() - 1;
	for(end; end > 0; end--){
		bool notSwapped = true;
		for(int i = 0; i < end; i++){
			if(v[i] > v[i + 1]){
				int temp = v[i + 1];
				v[i + 1] = v[i];
				v[i] = temp;
				notSwapped = false;
			}
		}
		if(notSwapped) return;
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

	bubbleSort(v);
	
	cout << "After sorting: ";
	for(int i = 0; i < n; i++){
		cout << v[i] << " ";
	}

	cout << endl;
	return 0;
}
