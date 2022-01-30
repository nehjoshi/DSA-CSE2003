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
    int nodeToDelete = 7;
    root = Delete(root, nodeToDelete);
    bool isThere = Search(root, nodeToDelete);
    if (isThere == true) cout << nodeToDelete << " is there in the tree" << endl;
    else cout << nodeToDelete << " is not there in the tree" << endl;
    return 0;
}