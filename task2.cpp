#include <iostream>
using namespace std;
int main()
{
    double num1, num2;
    char choice;
    cout << "\t\t\t\t***SIMPLE CALCULATOR***\n";
    cout << "Enter the first number:";
    cin >> num1;
    cout << "Enter the second number:";
    cin >> num2;
    cout << "Enter 1 for addition\n";
    cout << "Enter 2 for subtraction\n";
    cout << "Enter 3 for multiplication\n";
    cout << "Enter 4 for division\n";
    cin >> choice;
    switch (choice)
    {
    case '1':
        cout << "The sum of " << num1 << " and " << num2 << " is:" << num1 + num2 << endl;
        break;
    case '2':
        cout << "The difference of " << num1 << " and " << num2 << " is:" << num1 - num2 << endl;
        break;
    case '3':
        cout << "The multiplication of " << num1 << " and " << num2 << " is:" << num1 * num2 << endl;
        break;
    case '4':
        cout << "The division of " << num1 << " and " << num2 << " is:" << num1 / num2 << endl;
        break;
    default:
        cout << "Invalid Choice!!!\n";
        break;
    }
    return 0;
}