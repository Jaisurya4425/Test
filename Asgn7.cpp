#include <iostream>
using namespace std;

// Structure for tree node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Create new node
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert node into BST
Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// Pre-order Traversal
void preorder(Node* root) {
    if (root != NULL) {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// In-order Traversal
void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Post-order Traversal
void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
}

int main() {
    Node* root = NULL;

    int values[] = {9, 4, 15, 6, 12, 17, 2};
    int n = 7;

    // Insert values into BST
    for (int i = 0; i < n; i++) {
        root = insert(root, values[i]);
    }

    cout << "Pre-Order: ";
    preorder(root);
    cout << endl;

    cout << "In-Order: ";
    inorder(root);
    cout << endl;

    cout << "Post-Order: ";
    postorder(root);
    cout << endl;

    return 0;
}

