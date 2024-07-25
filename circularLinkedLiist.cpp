#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

void insertAtHead(Node*& head, int val) {
    Node* n = new Node(val);

    if (head == nullptr) {
        n->next = n;
        head = n;
        return;
    }

    Node* temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    head = n;
}

void insertAtTail(Node*& head, int val) {
    if (head == nullptr) {
        insertAtHead(head, val);
        return;
    }

    Node* n = new Node(val);
    Node* temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
}

void deleteAtHaed(node* &head){
    node * temp = head;
    while(temp-> != head) {
        temp = temp->next;
    }

    node* todelete = head;
    temp->next = head->next;
    head= head->next;

    delete todelete;
}

void deletion(node* &head , int pos) {
    if(pos ==1) {
        deleteAtHaed(head);
        return;
    }

    node*temp = head;
    int count = 1;

    while(count != pos-1) {
        temp = temp->next;
        count++;
    }

    node* todelete = temp->next;
    temp->next = temp->next=>next;

    delete todelete;
}

void display(Node* head) {
    if (head == nullptr) return;

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    Node* head = nullptr;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    display(head);
    insertAtHead(head, 5);
    display(head);
    deletion(head,5);
    display(head);
    return 0;
}
