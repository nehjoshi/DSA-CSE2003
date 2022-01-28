#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};
void Display(struct Node *head)
{
    if (head == NULL)
    {
        cout << "Circular queue is empty!" << endl;
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

struct Node *Enqueue(struct Node *head, int data){
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

struct Node *Dequeue(struct Node *head){
    int l = GetLength(head);

    if (l==0) {
        cout << "Circular Queue is empty!" << endl;
        
    }
    else if(l==1){
        head=NULL;
    }
    else {
        struct Node* newHead = head->next;
        struct Node* initial = head;
        while (head->next != initial) head = head->next;
        head->next = newHead;
        head = newHead;
    }
    return head;
}

int main(){
    struct Node *head = new Node;
    head = NULL;
    head = Enqueue(head, 10);
    head = Enqueue(head, 20);
    head = Enqueue(head, 30);
    head = Enqueue(head, 40);
    head = Dequeue(head);
    head = Dequeue(head);
    Display(head);
}
