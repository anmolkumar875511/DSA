#include <iostream>
using namespace std;

int main() {

    cout << "1. Simple if\n";
    int a = 10;
    if(a > 0){
        cout << "a is positive\n";
    }

    cout << "\n2. if-else\n";
    int b = -5;
    if(b >= 0){
        cout << "b is non-negative\n";
    } else {
        cout << "b is negative\n";
    }

    cout << "\n\n3. if - else if - else\n";
    int marks = 85;
    if(marks >= 90){
        cout << "Grade A\n";
    } else if(marks >= 75){
        cout << "Grade B\n";
    } else if(marks >= 50){
        cout << "Grade C\n";
    } else {
        cout << "Fail\n";
    }

    cout << "\n4. Nested if\n";
    int age = 20;
    if(age >= 18){
        if(age >= 21){
            cout << "Eligible for everything\n";
        } else {
            cout << "Eligible but with limits\n";
        }
    }

    cout << "\n\n5. if with logical operators\n";
    int x = 10, y = 20;
    if(x > 0 && y > 0){
        cout << "Both positive\n";
    }

    cout << "\n\n6. if with ternary operator\n";
    int num = 7;
    string res = (num % 2 == 0) ? "Even" : "Odd";
    cout << res << "\n";

    cout << "\n7. Multiple conditions\n";
    int p = 15;
    if(p > 10 && p < 20){
        cout << "p in range 11–19\n";
    }

    cout << "\n\n================ SWITCH CASES ================\n";

    cout << "\n8. Basic switch case\n";
    int day = 3;
    switch(day){
        case 1: cout << "Monday"; break;
        case 2: cout << "Tuesday"; break;
        case 3: cout << "Wednesday"; break;
        default: cout << "Invalid day";
    }
    cout << "\n";

    cout << "\n9. switch with fall-through\n";
    int level = 2;
    switch(level){
        case 1:
            cout << "Beginner\n";
        case 2:
            cout << "Intermediate\n";
        case 3:
            cout << "Advanced\n";
            break;
        default:
            cout << "Unknown level\n";
    }

    cout << "\n10. switch with char\n";
    char grade = 'B';
    switch(grade){
        case 'A': cout << "Excellent"; break;
        case 'B': cout << "Good"; break;
        case 'C': cout << "Average"; break;
        default: cout << "Invalid grade";
    }
    cout << "\n";

    cout << "\n11. switch with enum\n";
    enum Color {RED, GREEN, BLUE};
    Color c = GREEN;

    switch(c){
        case RED: cout << "Red color"; break;
        case GREEN: cout << "Green color"; break;
        case BLUE: cout << "Blue color"; break;
    }
    cout << "\n";

    cout << "\n12. switch inside loop\n";
    for(int i = 1; i <= 3; i++){
        switch(i){
            case 1: cout << "One\n"; break;
            case 2: cout << "Two\n"; break;
            case 3: cout << "Three\n"; break;
        }
    }

    cout << "\nProgram End\n";
    return 0;
}
