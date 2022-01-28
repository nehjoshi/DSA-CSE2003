#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
void Display(struct Node *head)
{
    if (head == NULL)
    {
        cout << "Circular linked list is empty!" << endl;
        return;
    }
    struct Node *initial = head;
    do
    {
        cout << head->data << endl;
        head = head->next;
    } while (head != initial);
}
int GetLength(struct Node *head)
{
    int length = 0;
    if (head == NULL)
    {
        return length;
    }
    else if (head != NULL && head->next == NULL)
        return 1;
    else
    {
        struct Node *initial = head;
        head = head->next;
        length = 1;
        while (head != initial)
        {
            length++;
            head = head->next;
        }
        return length;
    }
}
struct Node *Append(struct Node *head, int data) //Will add an element just before the head (and just after the element that points to the head)
{
    struct Node *temp = new Node;
    temp->data = data;
    if (GetLength(head) == 0)
    {
        head = temp;
        head->next = head;
    }
    else
    {
        struct Node *initial = head;
        while (head->next != initial)
        {
            head = head->next;
        }
        temp->next = initial;
        head->next = temp;
        head = initial;
    }
    return head;
}
struct Node *Front(struct Node *head, int data)
{
    struct Node *temp = new Node;
    temp->data = data;
    if (GetLength(head) == 0)
    {
        head = temp;
        head->next = head;
    }
    else
    {
        struct Node *initial = head;
        while (head->next != initial)
        {
            head = head->next;
        }
        temp->next = initial;
        head->next = temp;
        head = temp;
    }
    return head;
}
struct Node *Delete(struct Node *head, int data)
{
    struct Node *last = head;
    struct Node *initial = head;
    if (head == NULL)
    {
        cout << "LL is empty!" << endl;
        return head;
    }
    if (head->data == data)
    {
        while (last->next != head)
        {
            last = last->next;
        }
        last->next = head->next;
        head = NULL;
        head = last->next;
        return head;
    }
    while (last->next != head && last->next->data != data)
    {
        last = last->next;
    }
    if (last->next->data == data)
    {
        struct Node *temp = last->next;
        last->next = temp->next;
        while (last != initial)
            last = last->next;
        return last;
    }

    return head;
}
bool Find(struct Node *head, int data)
{
    struct Node *initial = head;
    while (head->next != initial)
    {
        if (head->data == data)
        {
            return true;
        }
        head = head->next;
    }
    return false;
}
struct Node *InsertAfterPosition(struct Node *head, int data, int pos)
{
    struct Node *initial = head;
    int i = 1;
    while (i != pos)
    {
        head = head->next;
        i+=1;
    }
    struct Node *temp = new Node;
    temp->data = data;
    temp->next = head->next;
    head->next = temp;
    head = initial;
    return head;

}
int main()
{

    struct Node *head = new Node;
    head = NULL;
    cout << "Adding 10, 20 and 30 to the LL" << endl;
    head = Append(head, 10);
    head = Append(head, 20);
    head = Append(head, 30);
    Display(head);
    cout << "Adding 4 and 5 to the front of the LL" << endl;
    head = Front(head, 5);
    head = Front(head, 4);
    Display(head);
    cout << "Deleting 20 from the LL" << endl;
    head = Delete(head, 20);
    Display(head);
    cout << "Now deleting 4" << endl;
    head = Delete(head, 4);
    Display(head);
    cout << "Now finding 10 in the linked list, searching..." << endl;
    int find = 10;
    if (Find(head, find) == true)
    {
        cout << find << " is in the LL" << endl;
    }
    else
    {
        cout << find << " is not in the LL" << endl;
    }
    cout << "Inserting 212 after 2nd position" << endl;
    head = InsertAfterPosition(head, 212, 2);
    Display(head);
    return 0;
}