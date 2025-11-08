#include <iostream>
using namespace std;
int main() {
    double num1, num2;
    char ope;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter an operator (+, -, *, /): ";
    cin >> ope;
    cout << "Enter second number: ";
    cin >> num2;
    cout << "\nResult: ";
    switch(ope) {
        case '+':
            cout << num1 + num2;
            break;
        case '-':
            cout << num1 - num2;
            break;
        case '*':
            cout << num1 * num2;
            break;
        case '/':
            if (num2 != 0)
                cout << num1 / num2;
            else
                cout << "Error! Division by zero is not allowed.";
            break;
        default:
            cout << "Invalid operator!";
            break;
    }
    cout << endl;
    return 0;
}