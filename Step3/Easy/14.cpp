#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int longestSubArrayLength(vector<int>& v, int k){
	int n = v.size(), sum = 0, maxL = 0;
	unordered_map<int, int> sumTill;

	for(int i = 0; i < n; i++) {
		sum = sum + v[i];
		
		if(sum == k) {
			maxL = max(maxL, i + 1);
		}

		int rem = sum - k;
		if(sumTill.find(rem) != sumTill.end()) {
			maxL = max<int>(maxL, i - sumTill[rem]);
		}

		if(sumTill.find(sum) == sumTill.end()) {
			sumTill[sum] = i;
		}
	}

	return maxL;
}

int main(){
	vector<int> v = {1, -2, 3, 7, 5};
	int k = 12;
	int length = longestSubArrayLength(v, k);
	if(length != 0){
		cout << "The length of the longest sub-array with sum " << k << " is: " << length << endl;
	} else {
		cout << "No sub-array with sum " << k << " found." << endl;
	}
	return 0;
}
