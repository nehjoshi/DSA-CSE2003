#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};
Node* GetNewNode(int data){
    Node *newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
Node* Insert(struct Node *root, int data){
    if (root == NULL){
        root = GetNewNode(data);
    }
    else if (data <= root->data){
        root->left = Insert(root->left, data);
    }
    else {
        root->right = Insert(root->right, data);
    }
    return root;
}

bool Search(struct Node* root, int value){
    if (root==NULL) return false;
    else if(root->data==value) return true;
    else if(value <= root->data) return Search(root->left, value);
    else return Search(root->right, value);
}

int main(){

    struct Node *root = new Node;
    root = NULL;
    root = Insert(root, 20);
    root = Insert(root, 10);
    int check = 5;
    if (Search(root, check)==true) cout << "Found " << check << " in the tree!" << endl;
    else cout << "Not found!" << endl;
    return 0;
}