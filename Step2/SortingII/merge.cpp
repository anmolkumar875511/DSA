#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& v, vector<int>& temp, int low, int mid, int high){
	int left = low, right = mid + 1, idx = low;

	while(left <= mid && right <= high){
		if(v[left] > v[right]) temp[idx++] = v[right++];
		else temp[idx++] = v[left++];
	}

	while(left <= mid) temp[idx++] = v[left++];

	while(right <= high) temp[idx++] =  v[right++];

	for(int i = low; i <= high; i++) v[i] = temp[i];

	return;
}

void mergeSortHelper(vector<int>& v, vector<int>& temp, int low, int high){
	if(low >= high) return;

	int mid = ((high - low) / 2) + low;

	mergeSortHelper(v, temp, low, mid);

	mergeSortHelper(v, temp, mid + 1, high);

	merge(v, temp, low, mid, high);

	return;
}

void mergeSort(vector<int>& v, int low, int high){
	if(v.size() < 2) return;
	vector<int> temp(v.size());
	mergeSortHelper(v, temp, low, high);
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

	mergeSort(v, 0, v.size() - 1);

	cout << "After sorting: ";
	for(int i = 0; i < n; i++){
		cout << v[i] << " ";
	}

	cout << endl;
	return 0;
}
