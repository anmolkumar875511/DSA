#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
	int n;
	cout << "Enter size: ";
	cin >> n;

	unordered_map<int, int> freq;
	int maxE, minE;
	int maxF = 0;
	int minF = n;
	int m;

	cout << "Enter elements: ";

	for(int i = 0; i < n; i++){
		cin >> m;
		freq[m]++;
		if(freq[m] > maxF){
			maxF = freq[m];
			maxE = m;
		}
		if(freq[m] < minF){
			minF = freq[m];
			minE = m;
		}
	}

	cout << "Most Frequent: " << maxE << endl;
	cout << "Least Frequent: " << minE << endl;

	return 0;
}
