#include<iostream>
using namespace std;

#define n 100

class Stack {
    int *arr;
    int top;

public:
    Stack() {
        arr = new int[n];
        top = -1;
    }

    void push(int x) {
        if(top == n - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        arr[++top] = x;
    }

    void pop() {
        if(top == -1) {
            cout << "No element to pop" << endl;
            return;
        }
        top--;
    }

    int Top() {
        if(top == -1) {
            cout << "No element in stack" << endl;
            return -1; // Returning a value since the function return type is int
        }
        return arr[top];
    }

    bool empty() {
        return top == -1;
    }

     
};

int main() {
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<"current top element of stack is :"<<endl;
    cout << st.Top() << endl;
    st.pop();
    cout<<"  top element of stack after pop operation is :"<<endl;
    cout << st.Top() << endl;
    st.pop();
    st.pop();
    st.pop(); // Attempt to pop when stack is empty
    cout << (st.empty() ? "Stack is empty" : "Stack is not empty") << endl;

    return 0;
}
