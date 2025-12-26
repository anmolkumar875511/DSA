#include<iostream>
#include<vector>
using namespace std;

vector<int> unionV(vector<int>& a, vector<int>& b) {

	vector<int> ans;
	int m = a.size(), n = b.size();
	int i = 0, j = 0;

	while(i < m && j < n) {
		if(a[i] < b[j]) {
			ans.push_back(a[i++]);
		}
		else if(a[i] > b [j]) {
			ans.push_back(b[j++]);
		}
		else{
			ans.push_back(a[i++]);
			j++;
		}
	}

	while(i < m) {
		ans.push_back(a[i++]);
	}

	while(j < n) {
		ans.push_back(b[j++]);
	}
	return ans;
}

int main() {
	vector<int> a = {1, 2, 2, 3, 4};
	vector<int> b = {2, 3, 5, 6};
	vector<int> result = unionV(a, b);
	cout << "Union of the two arrays is: ";
	for(int num : result) {
		cout << num << " ";
	}
	cout << endl;
	return 0;
}

