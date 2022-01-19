#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

void Push(struct Node **head, int value){
    struct Node *temp = new Node;

    if(*head == NULL){
        temp->data = value;
        temp->next = NULL;
        temp->prev = NULL;
        return;
    }

    temp->data = value;
    temp->next = *head;
    temp->prev = NULL;
    if (*head == NULL){
        (*head)->prev = temp;
        cout << "Called!";
    }
    *head = temp;

}
void Print(struct Node *head){
    struct Node *n = head;
    while (n != NULL){
        cout << n->data << endl;
        n = n->next;
    }
}

int main(){

    struct Node *head = new Node;
    head->data = 10;
    head->next=NULL;
    head->prev=NULL;
    Push(&head, 11);
    Push(&head, 12);
    cout << "Works!" << endl;
    Print(head);
    return 0;
}