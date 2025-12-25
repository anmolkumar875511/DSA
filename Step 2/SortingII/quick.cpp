#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>& v, int low, int high){

	// //Randomize pivot index
	//int pivotIndex = low + rand() % (high - low + 1);
	//int temp = v[pivotIndex];
	//v[pivotIndex] = v[high];
	//v[high] = temp;

	int pivot = v[high];
	int i = low;

	for(int j = low; j < high; j++){
		if(v[j] <= pivot){
			int temp = v[j];
			v[j] = v[i];
			v[i++] = temp;
		}
	}
	
	int temp = v[i];
	v[i] = v[high];
	v[high] = temp;

	return i;
}

void quickSort(vector<int>& v, int low, int high){

	if(low >= high) return;
	
	int partI = partition(v, low, high);

	quickSort(v, low, partI - 1);

	quickSort(v, partI + 1, high);
	
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

	quickSort(v, 0, v.size() - 1);

	cout << "After sorting: ";
	for(int i = 0; i < n; i++){
		cout << v[i] << " ";
	}

	cout << endl;
	return 0;
}

