/*
    A binary tree is a hierarchical data structure in which each node
    has at most two children, commonly referred to as the left child and
    the right child. The topmost node of the tree is known as the root node,
    which serves as the starting point for accessing all other nodes int
    the tree.

    Binary trees are widely used for:
    - searching
    - sorting
    - hierarchical data representation

*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = node->right = nullptr;
    return node;
}

// Preorder traversal (root, left, right)
void preorderTraversal(Node* node) {
    if (node == nullptr) return;
    // Visit the root node
    cout << node->data << ' ';
    // Recursively visit the left subtree
    preorderTraversal(node->left);
    // Recursively visit the right subtree
    preorderTraversal(node->right);
}

void inorderTraversal(Node* node) {
    if (node == nullptr) return;
    inorderTraversal(node->left);
    cout << node->data << ' ';
    inorderTraversal(node->right);
}

void postorderTraversal(Node* node) {
    if (node == nullptr) return;
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout << node->data << ' ';
}

int main() {
    // level 1
    Node* root = createNode(1);

    // level 2
    root->left = createNode(2);
    root->right = createNode(3);

    // level 3
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // level 4
    root->left->right->left = createNode(9);
    root->right->right->left = createNode(15);

    cout << "Preorder traversal: ";
    preorderTraversal(root);
    cout << endl;

    return 0;
}