#include <iostream>
#include <math.h>

using namespace std;

bool continueProgram = true;

void askForContinue()
{
    char ans;
    cout << "Do you want to continue? (y/n)" << endl;
    cin >> ans;
    if (ans == 'y')
    {
        continueProgram = true;
    }
    else
    {
        continueProgram = false;
    }
}

int main()
{
    while (continueProgram == true)
    {
        double a, b;
        cout << "Enter two numbers " << endl;
        cin >> a >> b;
        char op;
        cout << "Enter operation" << endl;
        cin >> op;
        double answer;
        double *ptr = &answer;
        switch (op)
        {
        case '+':
            cout << "The required sum is: " << a + b << endl;
            answer = a + b;
            askForContinue();
            break;
        case '-':
            cout << "The required difference is: " << a - b << endl;
            answer = a - b;
            askForContinue();
            break;
        case '*':
            cout << "The required product is: " << a * b << endl;
            answer = a * b;
            askForContinue();
            break;
        case '/':
            if (b == 0)
            {
                cout << "Division by zero is not allowed" << endl;
                askForContinue();
                break;
            }
            else
            {
                cout << "The required quotient is: " << a / b << endl;
                answer = a / b;
                askForContinue();
                break;
            }
        }
    }

    return 0;
}