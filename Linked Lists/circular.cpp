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
        cout << "Length of 1 or more" << endl;
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
    else {
        struct Node *initial = head;
        while(head->next != initial){
            head = head->next;
        }
        temp->next = initial;
        head->next = temp;
        head = temp;
    }
    return head;
}
int main()
{

    struct Node *head = new Node;
    head = NULL;
    head = Append(head, 10);
    head = Append(head, 20);
    head = Append(head, 30);
    head = Append(head, 40);
    head = Front(head, 5);
    head = Front(head, 4);
    Display(head);

    return 0;
}