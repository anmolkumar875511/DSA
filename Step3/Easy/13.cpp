#include<iostream>
#include<vector>
using namespace std;

int longestSubArrayLength(vector<int>& v, int k){
	int j = 0, sum = 0, maxL = -1, n = v.size();
	for(int i = 0; i < n; i++){
		sum = sum + v[i];
		while(sum > k){
			sum = sum - v[j++];
		}
		if(sum == k){
			maxL = max(maxL, (i - j + 1));
		}
	}
	return maxL;
}

int main(){
	vector<int> v = {1, 2, 3, 7, 5};
	int k = 12;
	int length = longestSubArrayLength(v, k);
	if(length != -1){
		cout << "The length of the longest sub-array with sum " << k << " is: " << length << endl;
	} else {
		cout << "No sub-array with sum " << k << " found." << endl;
	}
	return 0;
} 


