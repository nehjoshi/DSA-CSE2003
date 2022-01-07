#include <iostream>
using namespace std;
#define stack_size 5

int stack[stack_size], top = -1;

bool isFull(){
    return top==stack_size-1;
}
bool isEmpty(){
    return top==-1;
}
void push(int value){
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
        stack[top] == 0;
        top--;
    }
}

void view(){
    for (int i=0; i<=top; i++){
        cout << "Element " << i << ": " << stack[i] << endl;
    }
}

int main(){
    cout << "Pushing 2,3,4,5,6 to stack (19BEC1112)" << endl;
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    view();
    cout << "Popping one element from stack" << endl;
    pop();
    view();
    push(7);
    return 0;
}