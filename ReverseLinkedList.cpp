#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = NULL;
    }
};

void insertTail(node* &head, int val) {
    node* n = new node(val);
    if (head == NULL) {
        head = n;
        return;
    }
    node* temp = head;   
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
}

void display(node* head) {
    node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "-> ";
        temp = temp->next;
    }
    cout <<"Null"<< endl;
}

node* reverse(node* &head) {
    node* prevptr = NULL;
    node* currptr = head;
    node* nextptr;

    while (currptr != NULL) {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }
    head = prevptr;
    return head;
}

 
int main() {
    node* head = NULL;
    insertTail(head, 1);
    insertTail(head, 2);
    insertTail(head, 3);
    insertTail(head, 4);

    cout << "Original list: ";
    display(head);


    node* newhead = reverse(head);

    cout << "Reversed list: ";
    display(newhead);

     
    return 0;
}
