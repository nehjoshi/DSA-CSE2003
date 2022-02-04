//Post lab: Doubly circular Linked List (DC-LL)
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};
//19BEC1112
int Count(struct Node *head)
{
    int count = 1;
    if (head == NULL)
    {
        return 0;
    }
    while (head->next != NULL)
    {
        head = head->next;
        count += 1;
    }
    return count;
}
struct Node *InsertFront(struct Node *head, int data)
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
struct Node *InsertMiddle(struct Node *head, int value, int position)
{
    struct Node *temp = new Node;
    temp->data = value;
    if (head == NULL)
    {
        temp->next = NULL;
        temp->prev = NULL;
        head = temp;
        return head;
    }
    else if (position == 1)
    {
        temp->data = value;
        temp->prev = NULL;
        temp->next = head;
        head = temp;
        return head;
    }
    else if (position == Count(head) + 1)
    {
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
    struct Node *initial = head;
    for (int i = 1; i < position - 1; i++)
    {
        head = head->next;
    }
    temp->prev = head;
    temp->next = head->next;
    head->next = temp;
    head = head->next;
    head = head->next;
    head->prev = temp;
    head = initial;
    return head;
}
struct Node *InsertEnd(struct Node *head, int value)
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
struct Node *DeleteLast(struct Node *head)
{
    struct Node *initial = head;
    while (head->next != NULL)
    {
        head = head->next;
    }
    head->prev->next = NULL;
    head = initial;
    return head;
}
struct Node *DeleteFront(struct Node *head)
{
    head->next->prev = NULL;
    head = head->next;
    return head;
}
struct Node *DeleteMiddle(struct Node *head, int position)
{
    if (Count(head) == 1)
    {
        head = NULL;
        return head;
    }
    else if (position == 1)
    {
        head->next->prev = NULL;
        head = head->next;
        return head;
    }
    else if (position == Count(head) - 1)
    {
        struct Node *initial = head;
        while (head->next != NULL)
        {
            head = head->next;
        }
        head->prev->next = NULL;
        head = initial;
        return head;
    }
    struct Node *initial = head;
    for (int i = 1; i < position - 1; i++)
    {
        head = head->next;
    }
    struct Node *newNext = head->next->next;
    head->next = NULL;
    head->next = newNext;
    head = initial;
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
void Search(struct Node *head, int value)
{
    if (head == NULL)
    {
        cout << "DLL is empty!" << endl;
        return;
    }
    bool found = false;
    int position = 1;
    while (head->next != NULL)
    {
        if (head->data == value)
        {
            found = true;
            break;
        }
        else
        {
            head = head->next;
            position += 1;
            continue;
        }
    }
    if (found == true)
    {
        cout << "Element is found at position: " << position << endl;
    }
    else {
        cout << "Element not found!" << endl;
    }
    return;
}
int main()
{

    struct Node *head = new Node;
    head = NULL;
    cout << "Adding 11, 12, 13, 14, 15 and 16 to the doubly LL" << endl;
    head = InsertEnd(head, 11);
    head = InsertEnd(head, 12);
    head = InsertEnd(head, 13);
    head = InsertEnd(head, 14);
    head = InsertEnd(head, 15);
    head = InsertEnd(head, 16);
    Print(head);
    head = InsertFront(head, 10);
    cout << "Added 10 to the front" << endl;
    Print(head);
    cout << "Delete last element from doubly LL" << endl;
    head = DeleteLast(head);
    Print(head);
    cout << "Deleting front-most element from doubly LL" << endl;
    head = DeleteFront(head);
    Print(head);
    int data = 100;
    int position = 2;
    cout << "Inserting " << data << " at position " << position << " in the linked list" << endl;
    head = InsertMiddle(head, data, position);
    Print(head);
    cout << "Deleting element from position " << position << endl;
    head = DeleteMiddle(head, position);
    Print(head);
    cout << "Checking if 14 is present in the DLL" << endl;
    Search(head, 14);
    return 0;
}