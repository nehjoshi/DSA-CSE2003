#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};
struct Node* GetNewNode(int data){
    Node *newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
void Preorder(struct Node *root){
    if (root==NULL) return;
    cout << root->data << endl;
    Preorder(root->left);
    Preorder(root->right);
}
void Inorder(struct Node *root){
    if (root==NULL) return;
    Inorder(root->left);
    cout << root->data << endl;
    Inorder(root->right);
}
void Postorder(struct Node *root){
    if (root==NULL) return;
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << endl;
}
struct Node* Insert(struct Node *root, int data){
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
struct Node *FindMin(struct Node *root){
    struct Node *current = root;
    while (current->left != NULL){
        current = current->left;
    }
    return current;
}
struct Node* Delete(struct Node *root, int data){
    if (root==NULL) return root;
    else if(data < root->data) root->left = Delete(root->left, data);
    else if (data > root->data) root->right = Delete(root->right, data);
    else {
        if (root->left == NULL && root->right == NULL){ //Case if target node has no childrrn
            root = NULL;
        }
        else if (root->left == NULL){   //These two cases are for when the target node has 1 child
            struct Node *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL){
            struct Node *temp = root;
            root = root->left;
            temp = NULL;
        }
        else {  //When target node has two children
            struct Node *temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
        return root;
    }
    return root;

}

int main(){

    struct Node *root = new Node;
    root = NULL;
    root = Insert(root, 12);
    root = Insert(root, 5);
    root = Insert(root, 15);
    root = Insert(root, 3);
    root = Insert(root, 7);
    root = Insert(root, 1);
    root = Insert(root, 9);
    root = Insert(root, 13);
    root = Insert(root, 17);
    root = Insert(root, 2);
    root = Delete(root, 2);
    cout << "Visualizing the BST" << endl;
    Inorder(root);
    return 0;
}