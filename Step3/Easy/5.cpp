#include<iostream>
#include<vector>
using namespace std;

void rotateArrayByOne(vector<int>& v){

	int temp = v[0];
	int n = v.size();

	if(n < 2) return;

	for(int i = 1; i < n; i++){
		v[i - 1] = v[i];
	}

	v[n - 1] = temp;
}

int main(){
	vector<int> v = {1, 2, 3, 4, 5};
	rotateArrayByOne(v);
	cout << "The rotated array is: ";
	for(int i : v){
		cout << i << " ";
	}
	cout << endl;
	return 0;
}