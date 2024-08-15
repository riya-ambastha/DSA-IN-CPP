#include <iostream>

using namespace std;
 
struct Node {
    int data;
    Node* left;
    Node* right;
};
 
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}
 
void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}
 
Node* createSampleTree() {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    return root;
}

int main() {
    Node* root = createSampleTree();
    cout << "In-order traversal: ";
    inorderTraversal(root);
    cout << endl;
    return 0;
}