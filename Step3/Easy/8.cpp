#include<iostream>
#include<vector>
using namespace std;

bool linearSearch(vector<int>& v, int k) {
	for (int n : v) {
		if (n == k) {
			return true;
		}
	}
	return false;
}

int main() {
	vector<int> v = {1, 2, 3, 4, 5};
	int k = 3;
	if(linearSearch(v, k)) {
		cout << k << " found in the array." << endl;
	} else {
		cout << k << " not found in the array." << endl;
	}
	return 0;
}
