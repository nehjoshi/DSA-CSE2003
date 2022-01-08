#include <iostream>
using namespace std;
#define stack_size 100
//Code to create the stack
// ------------
double stack[stack_size];
int top = -1;

bool isFull()
{
    return top == stack_size - 1;
}
bool isEmpty()
{
    return top == -1;
}
void push(double value)
{
    if (isFull())
    {
        cout << "Stack overflow!" << endl;
        return;
    }
    else
    {
        top++;
        stack[top] = value;
    }
}
void pop()
{
    if (isEmpty())
    {
        cout << "Stack is already empty!" << endl;
        return;
    }
    else
    {
        stack[top] = 0;
        top--;
    }
}
// ------
double evaluate(string s)
{
    double result = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            push(s[i] - '0');
        }
        else
        {
            int op2 = stack[top];
            pop();
            int op1 = stack[top];
            pop();
            switch (s[i])
            {
            case '+':
                result = op1 + op2;
                break;
            case '-':
                result = op1 - op2;
                break;
            case '*':
                result = op1 * op2;
                break;
            case '/':
                result = op1 / op2;
                break;
            }
            push(result);
        }
    }
    return result;
}

int main()
{

    string s = "42/5+";
    cout << "Evaluation of postfix: " << s << " = " << evaluate(s) << endl;
    return '\0';
}