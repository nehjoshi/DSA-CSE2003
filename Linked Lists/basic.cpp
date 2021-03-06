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

void AddAtPosition(struct Node **head, int position, int data){  //0 5 10 15 20
    struct Node *temp = new Node;
    struct Node *n = *head;
    temp->data = data;
    int i = 1;
    while (i < position-1){
        n = n->next;
        i+=1;
    }
    temp->next = n->next;
    n->next = temp;
}
void DeleteNode(struct Node **list, int value){
    struct Node *n = *list;
    struct Node *temp = new Node;
    while(n->next->data!=value){
        n = n->next;
    }
    struct Node *prev = n;
    struct Node *del = n->next;
    struct Node *after = del->next;
    temp = after;
    free(del);
    n->next = temp;


}

int GetLength(struct Node **list){
    int length = 0;
    struct Node *n = *list;
    while (n != NULL){
        n = n->next;
        length += 1;
    }
    return length;

}
int Find(struct Node **list, int value){
    struct Node *n = *list;
    int length = GetLength(&n);
    int position = 1;
    while(n->data!=value){
        n = n->next;
        position++;
    }

    if (position==0 || position==length){
        cout << "Element doesn't exist!" << endl;
        return 0;
    }
    else {
        return position;
    }

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
    cout << "Now adding 24 at the fourth position" << endl;
    AddAtPosition(&head, 4, 24);
    Print(head);
    cout << "Length of the linked list: " << GetLength(&head) << endl;
    DeleteNode(&head, 24);
    cout << "Deleting 24 from the LL" << endl;
    Print(head);

    int position = Find(&head, 27);
    cout << "Position of 13 in the LL is: " << position << endl;
    return 0;
}