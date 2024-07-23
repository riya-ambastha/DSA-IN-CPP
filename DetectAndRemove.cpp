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
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout <<"NULL"<< endl;
}

// To make cycle
void makecycle(node* &head, int pos) {
    node* temp = head;
    node* startnode;

    int count = 1;
    while (temp->next != NULL) {
        if (count == pos) {
            startnode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startnode;
}

// To detect cycle
bool detectcycle(node* &head) {
    node* slow = head;
    node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow) {
            return true;
        }
    }
    return false;
}

// To remove cycle
void removecycle(node* &head) {
    node* slow = head;
    node* fast = head;

    do {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    fast = head;
    while (slow->next != fast->next) {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
}

int main() {
    node* head = NULL;
    insertTail(head, 1);
    insertTail(head, 2);
    insertTail(head, 3);
    insertTail(head, 4);
    insertTail(head, 5);
    insertTail(head, 6);
    insertTail(head, 7);
    
    makecycle(head, 3);

    cout << detectcycle(head) << endl; // Should print 1 (true) if a cycle is detected

    removecycle(head);

    cout << detectcycle(head) << endl; // Should print 0 (false) if the cycle is removed

    display(head);

    return 0;
}
