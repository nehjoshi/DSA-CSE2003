#include <iostream>
using namespace std;

struct Node
{
    int value;
    Node *next;
};
int rear = -1;

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

void Enqueue(struct Node **head, int data)
{
    struct Node *temp = new Node;
    temp->value = data;
    if (rear == -1)
    {
        temp->next = NULL;
        *head = temp;
        rear += 1;
        return;
    }
    temp->next = *head;
    *head = temp;
    rear++;
    return;
}
void Dequeue(struct Node **head)
{
    struct Node *n = *head;
    if (rear == -1)
    {
        cout << "Stack is empty!" << endl;
        return;
    }
    if (rear == 0)
    {
        *head = NULL;
        rear = -1;
        return;
    }
    while (n->next->next != NULL)
    {
        n = n->next;
    }
    struct Node *del = n->next;
    free(del);
    n->next = NULL;
    rear = rear - 1;
    return;
}

int main()
{
    struct Node *head = new Node;
    Enqueue(&head, 10);
    Display(head);
    Enqueue(&head, 20);
    Display(head);
    Dequeue(&head);
    Display(head);
    return 0;
}
//To do: circular queue
//Postlab: tower of hanoi and balancing parenthesis and stack using queue