#include <iostream>
#include <vector>
using namespace std;

int main() {

    cout << "1. for loop\n";
    for(int i = 1; i <= 5; i++){
        cout << i << " ";
    }
    cout << "\n\n";

    cout << "2. while loop\n";
    int i = 1;
    while(i <= 5){
        cout << i << " ";
        i++;
    }
    cout << "\n\n";

    cout << "3. do-while loop\n";
    int j = 1;
    do{
        cout << j << " ";
        j++;
    }while(j <= 5);
    cout << "\n\n";

    cout << "4. range-based for loop\n";
    vector<int> v = {10, 20, 30, 40};
    for(int x : v){
        cout << x << " ";
    }
    cout << "\n\n";

    cout << "5. infinite loop (with break)\n";
    int k = 1;
    while(true){
        cout << k << " ";
        if(k == 5) break;
        k++;
    }
    cout << "\n\n";

    cout << "6. nested loop\n";
    for(int r = 1; r <= 3; r++){
        for(int c = 1; c <= 3; c++){
            cout << "(" << r << "," << c << ") ";
        }
        cout << "\n";
    }
    cout << "\n";

    cout << "7. loop with continue\n";
    for(int x = 1; x <= 5; x++){
        if(x == 3) continue;
        cout << x << " ";
    }
    cout << "\n\n";

    cout << "8. loop with break\n";
    for(int x = 1; x <= 5; x++){
        if(x == 4) break;
        cout << x << " ";
    }
    cout << "\n\n";

    cout << "9. iterator loop\n";
    vector<int> a = {5, 10, 15};
    for(auto it = a.begin(); it != a.end(); it++){
        cout << *it << " ";
    }
    cout << "\n\n";

    cout << "10. reverse loop\n";
    for(int x = 5; x >= 1; x--){
        cout << x << " ";
    }
    cout << "\n\n";

    cout << "11. for loop without body\n";
    int sum = 0;
    for(int x = 1; x <= 5; sum += x, x++);
    cout << "Sum = " << sum << "\n\n";

    cout << "12. loop using auto keyword\n";
    vector<int> b = {1,2,3};
    for(auto &val : b){
        val *= 2;
        cout << val << " ";
    }
    cout << "\n\n";

    cout << "13. labeled loop (with goto - NOT recommended)\n";
    int n = 1;
start:
    cout << n << " ";
    n++;
    if(n <= 5) goto start;

    cout << "\n\nProgram End\n";
    return 0;
}
