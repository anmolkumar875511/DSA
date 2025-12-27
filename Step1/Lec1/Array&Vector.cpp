#include<iostream>
#include<vector>
using namespace std;

int main(){
    // Arrays and Vectors in C++
    int arr[5] = {1,2,3,4,5};
    vector<int> v = {1,2,3};
    v.push_back(4);
    v.pop_back();

    cout << "Array elements: ";
    for(int i = 0; i < 5; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Vector elements: ";
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;


    // Vector of pairs
    vector<pair<int,int>> vp;
    vp.push_back({1,2});
    vp.push_back({3,4});

    for(auto p : vp) {
        cout << p.first << " " << p.second << "\n";
    }

    // Iterators
    vector<int> v = {1,2,3};

    for(auto it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

return 0;
}