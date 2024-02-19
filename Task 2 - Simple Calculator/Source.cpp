#include <iostream>
using namespace std;

float calculate(float num1, float num2)
{
    float result = 0;
    int choice;

    cout << "Choose an operation: \n";
    cout << "1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n";
    cin >> choice;
    cout << "\n";
    switch (choice)
    {
    case 1:
        result = num1 + num2;
        cout << "Addition of " << num1 << " and " << num2 << " is " << result;
        break;
    case 2:
        result = num1 - num2;
        cout << "Subtraction of " << num1 << " and " << num2 << " is " << result;
        break;
    case 3:
        result = num1 * num2;
        cout << "Multiplication of " << num1 << " and " << num2 << " is " << result;
        break;
    case 4:
        result = num1 / num2;
        cout << "Division of " << num1 << " and " << num2 << " is " << result;
        break;
    default:
        cout << "Invalid choice\n";
        calculate(num1, num2);
    }
    return result;
}


float calculator()
{
    float num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    float result;
    result = calculate(num1, num2);
    
    return result;
}

int main()
{
    cout << "Welcome to the calculator program!\n";

	calculator();
	char choice;
	cout << "\n\nDo you want to continue? (y/n): ";
    cin >> choice;
    if (choice == 'y' || choice == 'Y')
    {
		calculator();
	}
    else if (choice == 'n' || choice == 'N')
    {
		cout << "Thank you for using the calculator!";
	}
    else
    {
		cout << "Invalid choice";
	}
    return 0;
}