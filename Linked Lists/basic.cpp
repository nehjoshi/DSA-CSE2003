#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void Print(struct Node *n)
{
    while (n != NULL)
    {
        cout << n->data << endl;
        n = n->next;
    }
}

void AddAtFront(struct Node **head, int data)
{
    struct Node *temp = new Node;
    temp->data = data;
    temp->next = *head;
    *head = temp;
}
void Append(struct Node **head, int data){
    struct Node *temp = new Node;
    struct Node *last = *head;
    temp->next = NULL;
    temp->data = data;
    while(last->next != NULL) {
        last = last->next;
    }
    last->next = temp;

}

int main()
{

    struct Node *head = new Node;
    head->data = 0;
    head->next = NULL;

    Print(head);
    AddAtFront(&head, 12);
    cout << "Now adding 12" << endl;
    Print(head);
    AddAtFront(&head, 11);
    cout << "Now adding 11" << endl;
    Print(head);
    Append(&head, 13);
    Append(&head, 14);
    cout << "Now appending 13 and 14" << endl;
    Print(head);
    return 0;
}