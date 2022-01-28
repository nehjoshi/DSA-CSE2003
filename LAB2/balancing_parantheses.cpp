#include <iostream>
using namespace std;

struct Node
{
    char data;
    Node *next;
};

void Display(struct Node *head)
{
    if (head == NULL)
    {
        cout << "Stack is empty" << endl;
    }
    while (head != NULL)
    {
        cout << head->data << endl;
        head = head->next;
    }
}
int GetLength(struct Node *head)
{
    int length = 0;
    if (head == NULL)
        return length;
    while (head != NULL)
    {
        length += 1;
        head = head->next;
    }
    return length;
}
struct Node *Push(struct Node *head, char data)
{
    int l = GetLength(head);
    struct Node *temp = new Node;
    temp->data = data;
    if (l == 0)
    {
        temp->next = NULL;
        head = temp;
    }
    else
    {
        struct Node *initial = head;
        while (head->next != NULL)
        {
            head = head->next;
        }
        temp->next = NULL;
        head->next = temp;
        head = initial;
    }
    return head;
}

struct Node *Pop(struct Node *head)
{
    if (GetLength(head) == 0)
    {
        cout << "Stack is empty!" << endl;
        return head;
    }
    else if (GetLength(head) == 1){
        head = NULL;
        return head;
    }
    else
    {
        struct Node *initial = head;
        while (head->next->next != NULL)
        {
            head = head->next;
        }
        head->next = NULL;
        head = initial;
    }
    return head;
}

char GetTop(struct Node *head)
{
    char top;
    while (head->next != NULL)
    {
        head = head->next;
    }
    top = head->data;
    return top;
}
bool CheckBalanced(string s, struct Node *head)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(')
        {
            head = Push(head, s[i]);
            continue;
        }
        if (GetLength(head) == 0)
            return false;

        if (s[i] == ')')
        {
            char top = GetTop(head);
            head = Pop(head);
            if (top == '[' || top == '{')
            {
                break;
                return false;
            } else continue;
        }
        else if (s[i] == ']')
        {
            char top = GetTop(head);
            head = Pop(head);
            if (top == '(' || top == '{')
            {
                break;
                return false;
            } else continue;
        }
        else if (s[i] == '}')
        {
            char top = GetTop(head);
            head = Pop(head);
            if (top == '[' || top == '('){
                break;
                return false;
            } else continue;
        }
    }
    if (GetLength(head) == 0)
        return true;
    else
        return false;
}

int main()
{
    struct Node *head = new Node;
    head = NULL;
    if (CheckBalanced("{{{(())}}}", head))
        cout << "Balanced!" << endl;
    else
        cout << "Unbalanced!" << endl;
}