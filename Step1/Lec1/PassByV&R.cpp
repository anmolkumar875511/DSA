#include <iostream>
using namespace std;

void byValue(int x){ x++; }
void byRef(int &x){ x++; }

int main(){
    int a = 5;
    byValue(a); // a = 5
    byRef(a);   // a = 6
}
