#include<iostream>
using namespace std;

void pattern1(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << " * ";
        }
        cout << endl;
    }
}

void pattern2(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cout << " * ";
        }
        cout << endl;
    }
}

void pattern3(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cout << j+1 << " ";
        }
        cout << endl;
    }
}

void pattern4(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cout << i+1 << " ";
        }
        cout << endl;
    }
}

void pattern5(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-i; j++){
            cout << " * ";
        }
        cout << endl;
    }
}

void pattern6(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i; j++){
            cout << j + 1 << " "; 
        }
        cout << endl;
    }
}

void pattern7(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 2 * n; j++){
            if(j <= n - i){
                cout << "   ";
            }
            else if (j > n - i && j < n + i){
                cout << " * ";
            }
            else{
                cout << "   ";
            }
        }
        cout << endl;
    }
}

void pattern8(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 2 * n; j++){
            if(j < i){
                cout << "   ";
            }
            else if (j >= i && j <= 2 * n - i){
                cout << " * ";
            }
            else{
                cout << "   ";
            }
        }
        cout << endl;
    }
}


void pattern9(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n - i; j++){
            cout << "   ";
        }
        for(int j = 1; j <= 2 * i - 1; j++){
            cout << " * ";
        }
        cout << endl;
    }
    for(int i = n; i >= 1; i--){
        for(int j = 1; j <= n - i; j++){
            cout << "   ";
        }
        for(int j = 1; j <= 2 * i - 1; j++){
            cout << " * ";
        }
        cout << endl;
    }
}

void pattern10(int n){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cout << " * ";
        }
        cout << endl;
    }
    for(int i = n - 1; i >= 1; i--){
        for(int j = 1; j <= i; j++){
            cout << " * ";
        }
        cout << endl;
    }
}

void pattern11(int n){
    for(int i = 0; i < n; i++){
        int val;
        if (i % 2 == 0){
            val = 1;
        }
        else{
            val = 0;
        }
        
        for(int j = 0; j <= i; j++){
            
            cout << " " << val << " ";
            val = 1 - val;
        }
        cout << endl;
    }
}

void pattern12(int n){
    for (int i = 1; i <= n; i++){
        for(int j = 1; j <= 2 * n; j++){
            if(j <= i){
                cout << " " << j << " ";
            }
            else if (j <= 2 * n - i){
                cout << "   ";
            }
            else{
                cout << " " << 2 * n - j + 1 << " ";
            }
        }
        cout << endl;
    }
}

void pattern13(int n){
    int k = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            cout << " " << k << " ";
            k = k + 1;
        }
        cout << endl;
    }
}
void pattern14(int n){
    for(int i = 1; i <= n; i++){
        char c = 'A';
        for(int j = 1; j <= i; j++){
            cout << " " << c << " ";
            c = (int) c + 1;
        }
        cout << endl;
    }
}

void pattern15(int n){
    for (int i = 0; i < n; i++){
        char c = 'A';
        for (int j = 0; j < n - i; j++){
            cout << " " << c << " ";
            c = (int) c + 1;
        }
        cout << endl;
    }
    
}

void pattern16(int n){
    char c = 'A';
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cout << " " << c << " ";
        }
        c = (int) c + 1;
        cout << endl;
    }
}

void pattern17(int n){
    for(int i = 0; i < n; i++){
        char c = 'A';
        for(int j = 0; j < n + i; j++){
            if(j < n - i - 1){
                cout << "   ";
            }
            else if(j < n){
                cout << " " << c << " ";
                c = (int) c + 1;
            }
            else if (j == n){
                c = (int) c - 2;
                cout << " " << c << " ";
            }
            else{
                c = (int) c - 1;
                cout << " " << c << " ";
            }
        }
        cout << endl;
    }
}  

void pattern18(int n){
    for(int i = 0; i < n; i++){
        char c = 'A' + n - i - 1;
        for(int j = 0; j <= i; j++){
           cout << " " << c << " ";
           c = (int) c + 1;
        }
        cout << endl;
    }
}

void pattern19(int n){
    for(int i = 0; i < 2*n; i++){
        for(int j = 0; j < 2*n; j++){
            if(i < n){
                    if (j < n - i || j >= n + i){
                        cout << " * ";
                    }
                    else{
                        cout << "   ";
                    }
            }
            else{
                if (j <= i - n || j >= 3*n - i - 1){
                    cout << " * ";
                }
                else{
                    cout << "   ";
                }
            }
            
        }
        cout << endl;
    }
}

void pattern20(int n){
    for(int i = 0; i < 2 * n - 1; i++){
        for(int j = 0; j < 2*n; j++){
            if (i < n){
                if( j <= i || j >= 2 * n - i -1){
                    cout << " * ";
                }
                else{
                    cout << "   ";
                }
            }
            else{
                if( j < 2*n - i -1 || j > i){
                    cout << " * ";
                }
                else{
                    cout << "   ";
                }
            }
        }
        cout << endl;
    }
}

void pattern21(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (j == 0 || j == n - 1 || i == 0 || i == n - 1){
                cout << " * ";
            }
            else{
                cout << "   ";
            }
        }
        cout << endl;
    }
}

void pattern22(int n){
    for(int i = 0; i < 2 * n - 1; i++){
        for(int j = 0; j < 2 * n - 1; j++){
            if (i < n){
                if(j <= i){
                    cout << " " << n - j << " ";
                }
                else if (j >= 2 * n - i - 2){
                    cout << " " << j - n + 2 << " ";
                }
                else{
                    cout << " " << n - i << " ";
                }
            }
            else{
                if(j < 2 * n - i -1){
                    cout << " " << n - j << " ";
                }
                else if (j >= i){
                    cout << " " << j - n + 2 << " ";
                }
                else{
                    cout << " " << i - n + 2 << " ";
                }
            }
        }
        cout << endl;
    }
}

int main() {
    cout << "Patterns Module" << endl;
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    pattern1(n);
    cout << endl;
    pattern2(n);
    cout << endl;
    pattern3(n);
    cout << endl;
    pattern4(n);
    cout << endl;
    pattern5(n);
    cout << endl;
    pattern6(n);
    cout << endl;
    pattern7(n);
    cout << endl;
    pattern8(n);
    cout << endl;
    pattern9(n);
    cout << endl;
    pattern10(n);
    cout << endl;
    pattern11(n);
    cout << endl;
    pattern12(n);
    cout << endl;
    pattern13(n);
    cout << endl;
    pattern14(n);
    cout << endl;
    pattern15(n);
    cout << endl;
    pattern16(n);
    cout << endl;
    pattern17(n);
    cout << endl;
    pattern18(n);
    cout << endl;
    pattern19(n);
    cout << endl;
    pattern20(n);
    cout << endl;
    pattern21(n);
    cout << endl;
    pattern22(n);
    return 0;
}
