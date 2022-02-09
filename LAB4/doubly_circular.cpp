#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

int GetLength(struct Node *head)
{
    int length = 1;
    if (head == NULL)
        return 0;
    else if (head != NULL && head->next == NULL)
        return 1;
    struct Node *initial = head;
    head = head->next;
    while (head != initial)
    {
        head = head->next;
        length += 1;
    }
    return length;
}
void Display(struct Node *head)
{
    struct Node *initial = head;
    if (head == NULL)
    {
        cout << "Circular DLL is empty!" << endl;
        return;
    }
    do
    {
        cout << head->data << endl;
        head = head->next;
    } while (head != initial);
}
struct Node *InsertEnd(struct Node *head, int data)
{
    struct Node *temp = new Node;
    struct Node *initial = head;
    temp->data = data;
    if (head == NULL)
    {
        temp->next = NULL;
        temp->prev = NULL;
        head = temp;
        return head;
    }
    else if (GetLength(head) == 1)
    {
        temp->prev = head;
        temp->next = head;
        head->next = temp;
        head->prev = temp;
        head = initial;
        return head;
    }
    temp->next = head;
    head->prev = temp;

    while (head->next != initial)
    {
        head = head->next;
    }
    temp->prev = head;
    head->next = temp;
    head = initial;
    return head;
}
struct Node *InsertFront(struct Node *head, int data)
{
    struct Node *temp = new Node;
    struct Node *initial = head;
    temp->data = data;
    if (head == NULL)
    {
        temp->next = NULL;
        temp->prev = NULL;
        head = temp;
        return head;
    }
    else if (GetLength(head) == 1)
    {
        temp->prev = head;
        temp->next = head;
        head->next = temp;
        head->prev = temp;
        head = temp;
        return head;
    }
    temp->next = head;
    head->prev = temp;
    while (head->next != initial)
    {
        head = head->next;
    }
    temp->prev = head;
    head->next = temp;
    head = temp;
    return head;
}
struct Node *InsertAtPosition(struct Node *head, int data, int position)
{
    struct Node *initial = head;
    struct Node *temp = new Node;
    temp->data = data;
    int count = 0;
    while (count < position - 2)
    {
        head = head->next;
        count += 1;
    }
    temp->prev = head;
    temp->next = head->next->next;
    head->next = temp;
    head = head->next;
    head = head->next;
    head->prev = temp;
    head = initial;
    return head;
}
struct Node *DeleteFront(struct Node *head)
{
    if (GetLength(head) == 1)
    {
        head = NULL;
        return head;
    }
    else if (GetLength(head) == 2)
    {
        head = head->next;
        head->prev = NULL;
        head->next = NULL;
        return head;
    }
    struct Node *initial = head;
    struct Node *NewInitial = head->next;
    head = head->prev;
    head->next = NewInitial;
    NewInitial->prev = head;
    head = NewInitial;
    return head;
}
struct Node *DeleteEnd(struct Node *head)
{
    if (GetLength(head) == 1)
    {
        head = NULL;
        return head;
    }
    else if (GetLength(head) == 2)
    {
        head->next = NULL;
        head->prev = NULL;
        return head;
    }
    struct Node *initial = head;
    head = head->prev;
    head = head->prev;
    head->next = initial;
    initial->prev = head;
    head = initial;
    return head;
}
struct Node *DeleteAtPosition(struct Node *head, int position){
    struct Node *initial = head;
    int count = 0;
    while (count < position - 2){
        head = head->next;
        count += 1;
    }
    struct Node *temp = head->next->next;
    temp->prev = head;
    head->next = temp;
    head = initial;
    return head;
}
bool Search(struct Node *head, int query){
    struct Node *initial = head;
    do {
        if (head->data == query){
            return true;
        }
        head = head->next;
    } while(head != initial);
    return false;
}

int main()
{

    struct Node *head = new Node;
    head = NULL;
    cout << "Inserting 10, 11, 12, 13 and 14 at the end of the circular DLL" << endl;
    head = InsertEnd(head, 10);
    head = InsertEnd(head, 11);
    head = InsertEnd(head, 12);
    head = InsertEnd(head, 13);
    head = InsertEnd(head, 14);
    Display(head);
    cout << "Inserting 8 and 9 at the front of the circular DLL" << endl;
    head = InsertFront(head, 9);
    head = InsertFront(head, 8);
    Display(head);
    cout << "Inserting 100 at 4th position of circular DLL" << endl;
    head = InsertAtPosition(head, 100, 4);
    Display(head);
    cout << "Deleting 3rd element from circular DLL" << endl;
    head = DeleteAtPosition(head, 3);
    Display(head);
    cout << "Deleting from front of circular DLL" << endl;
    head = DeleteFront(head);
    Display(head);
    cout << "Deleting from end of circular DLL" << endl;
    head = DeleteEnd(head);
    Display(head);
    cout << "Searching for 9 in the circular DLL" << endl;
    cout << "Searching..." << endl;
    if (Search(head, 9)) cout << "9 is found in the circular DLL!" << endl;
    else cout << "9 is NOT found!" << endl;

    return 0;
}
