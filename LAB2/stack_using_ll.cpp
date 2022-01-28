#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *next;
};
int top = -1;

void Display(struct Node *head)
{
    cout << "-----------" << endl;
    while (head != NULL)
    {
        cout << head->value << endl;
        head = head->next;
    }
    cout << "-----------" << endl;
    return;
}
void Push(struct Node **head, int data)
{
    struct Node *temp = new Node;
    struct Node *n = *head;
    temp->value = data;
    temp->next = NULL;
    if (top == -1)
    {
        (*head) = temp;
        top += 1;
        return;
    }
    while (n->next != NULL)
    {
        n = n->next;
    }
    top += 1;
    n->next = temp;
    return;
}

void Pop(struct Node **head)
{
    struct Node *n = *head;
    if (top == -1)
    {
        cout << "Stack is empty!" << endl;
        return;
    }
    if (top == 0)
    {
        *head = NULL;
        top = -1;
        return;
    }
    while (n->next->next != NULL)
    {
        n = n->next;
    }
    struct Node *del = n->next;
    free(del);
    n->next = NULL;
    top = top - 1;
    return;
}

int main()
{

    struct Node *head = new Node;
    Push(&head, 20);
    Push(&head, 30);
    Display(head);
    cout << "Now popping" << endl;
    Pop(&head);
    Display(head);
    return 0;
}