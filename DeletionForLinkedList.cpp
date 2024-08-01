#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Function to insert a new node at the end
void insert(Node*& head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    
    if (head == nullptr) {
        head = newNode;
        return;
    }
    
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node with a specific key
void deleteNode(Node*& head, int key) {
    Node* temp = head;
    Node* prev = nullptr;
    
    // If the head node itself holds the key to be deleted
    if (temp != nullptr && temp->data == key) {
        head = temp->next;
        delete temp;
        return;
    }
    
    // Search for the key to be deleted
    while (temp != nullptr && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    
    // If key was not present in linked list
    if (temp == nullptr) return;
    
    // Unlink the node from linked list
    prev->next = temp->next;
    
    delete temp;
}

// Function to print the linked list
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    
    cout << "Linked list before deletion: ";
    printList(head);
    
    deleteNode(head, 3);
    
    cout << "Linked list after deletion: ";
    printList(head);
    
    return 0;
}
 
