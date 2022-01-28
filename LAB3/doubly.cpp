#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

struct Node *Push(struct Node *head, int value)
{
    struct Node *temp = new Node;

    if (head == NULL)
    {
        temp->data = value;
        temp->next = NULL;
        temp->prev = NULL;
        head = temp;
        return head;
    }
    struct Node *initial = head;
    temp->next = NULL;
    temp->data = value;
    while (head->next != NULL)
        head = head->next;
    temp->prev = head;
    head->next = temp;
    head = initial;
    return head;
}
struct Node *Front(struct Node *head, int data)
{
    struct Node *temp = new Node;
    if (head == NULL)
    {
        temp->data = data;
        temp->next = NULL;
        temp->prev = NULL;
        head = temp;
        return head;
    }
    temp->data = data;
    temp->prev = NULL;
    temp->next = head;
    head = temp;
    return head;
}
struct Node *DeleteLast(struct Node *head){
    struct Node *initial = head;
    while (head->next != NULL){
        head = head->next;
    }
    head->prev->next = NULL;
    head = initial;
    return head;
}
struct Node *DeleteFront(struct Node *head){
    head->next->prev = NULL;
    head = head->next;
    return head;
}
void Print(struct Node *head)
{
    struct Node *n = head;
    while (head != NULL)
    {
        cout << head->data << endl;
        head = head->next;
    }
}

int main()
{

    struct Node *head = new Node;
    head = NULL;
    cout << "Adding 11, 12, 13 and 14 to the doubly LL" << endl;
    head = Push(head, 11);
    head = Push(head, 12);
    head = Push(head, 13);
    head = Push(head, 14);
    Print(head);
    head = Front(head, 10);
    cout << "Added 10 to the front" << endl;
    Print(head);
    cout << "Delete last element from doubly LL" << endl;
    head = DeleteLast(head);
    Print(head);
    cout << "Deleting front-most element from doubly LL" << endl;
    head = DeleteFront(head);
    Print(head);
    return 0;
}