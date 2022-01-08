#include <iostream>
using namespace std;
#define stack_size 100
//Code to create the stack
// ------------
char stack[stack_size];
int top = -1;

bool isFull(){
    return top==stack_size-1;
}
bool isEmpty(){
    return top==-1;
}
void push(char value){
    if (isFull()){
        cout << "Stack overflow!" << endl;
        return;
    }
    else {
    top++;
    stack[top] = value;
    }
}
void pop(){
    if (isEmpty()){
        cout << "Stack is already empty!" << endl;
        return;
    }
    else {
        stack[top] == '\0';
        top--;
    }
}
// ------
int calcPredidence(char c){ //Calculate prededence of each operator according to BODMAS
    if (c=='^'){
        return 3;
    }
    else if(c=='*' || c=='/'){
        return 2;
    }
    else if (c=='+' || c=='-'){
        return 1;
    }
    else return -1;
}

string convert(string s){
    string result;
    for (int i=0; i<s.length(); i++){
        if (s[i] >= 'a' && s[i] <= 'z'){
            result += s[i];
        }
        else if (s[i]=='('){
            push(s[i]);
        }
        else if (s[i]==')'){
            while (!isEmpty() && stack[top]!='('){
                result += stack[top];
                pop();
            }
            if (!isEmpty()){
                pop();
            }
        }
        else {
            while (!isEmpty() && calcPredidence(stack[top])>calcPredidence(s[i])){
                result += stack[top];
                pop();
            }
            push(s[i]);
        }
    }
    while (!isEmpty()){
        result += stack[top];
        pop();
    }
    return result;
}

int main(){

    string s = "(a+b)*c";
    cout << "Conversion of: " << s << " to postfix is: " << convert(s) << endl;
    return 0;
}