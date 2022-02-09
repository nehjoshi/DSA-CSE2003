// Post lab: Polynomial MUL and DIV
#include <iostream>
#include <string.h>
using namespace std;

struct Node
{
    float coeff;
    int power;
    struct Node *next;
};
string Display(struct Node *head)
{
    string result = "";
    while (head != NULL)
    {
        result += to_string(head->coeff);
        result += "x^";
        result += to_string(head->power);
        if (head->next != NULL)
            result += " + ";
        head = head->next;
    }
    return result;
}
int GetLength(struct Node *head)
{
    int length = 1;
    if (head == NULL)
        return 0;
    while (head->next != NULL)
    {
        head = head->next;
        length += 1;
    }
    return length;
}
struct Node *Create(struct Node *head, float coeff, int power)
{
    struct Node *temp = new Node;
    if (head == NULL)
    {
        temp->next = NULL;
        temp->power = power;
        temp->coeff = coeff;
        head = temp;
        return head;
    }
    struct Node *initial = head;
    while (head->next != NULL)
    {
        head = head->next;
    }
    temp->coeff = coeff;
    temp->power = power;
    temp->next = NULL;
    head->next = temp;
    head = initial;
    return head;
}
struct Node *MulPoly(struct Node *f1, struct Node *f2)
{
    int l1 = GetLength(f1);
    int l2 = GetLength(f2);
    struct Node *initialf2 = f2;
    struct Node *result = new Node;
    result = NULL;
    while (f1 != NULL)
    {
        while (f2 != NULL)
        {
            float resultCoeff = f1->coeff * f2->coeff;
            result = Create(result, resultCoeff, f1->power + f2->power);
            f2 = f2->next;
        }
        f2 = initialf2;
        f1 = f1->next;
    }
    return result;
}
int main()
{

    struct Node *head1 = new Node;
    struct Node *head2 = new Node;
    head1 = NULL;
    head2 = NULL;
    cout << "---------- FIRST POLYNOMIAL ----------" << endl;
    char c1;
    do
    {
        float coeff;
        int power;
        cout << "Enter coefficient of node" << endl;
        cin >> coeff;
        cout << "Enter power of node (highest first)" << endl;
        cin >> power;
        head1 = Create(head1, coeff, power);
        cout << "Do you want to add more nodes? (y/n)" << endl;
        cin >> c1;
    } while (c1 != 'n');

    cout << "---------- SECOND POLYNOMIAL ----------" << endl;
    char c2;
    do
    {
        float coeff;
        int power;
        cout << "Enter coefficient of node" << endl;
        cin >> coeff;
        cout << "Enter power of node (highest first)" << endl;
        cin >> power;
        head2 = Create(head2, coeff, power);
        cout << "Do you want to add more nodes? (y/n)" << endl;
        cin >> c2;
    } while (c2 != 'n');

    struct Node *result = new Node;
    result = NULL;
    result = MulPoly(head1, head2);

    cout << "First polynomial: " << Display(head1) << endl;
    cout << "Second polynomial: " << Display(head2) << endl;
    cout << "Resultant polynomial: " << Display(result) << endl;
}