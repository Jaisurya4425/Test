#include <iostream>
using namespace std;

#define MAX 10   // Maximum size of stack

class Stack {
    int top;
    int arr[MAX];

public:
    Stack() {
        top = -1;
    }

    // Push operation
    void push(int value) {
        if (top == MAX - 1) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        top++;
        arr[top] = value;
        cout << value << " pushed into stack" << endl;
    }

    // Pop operation
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        cout << arr[top] << " popped from stack" << endl;
        top--;
    }

    // Display stack
    void display() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return;
        }

        cout << "Stack elements:" << endl;
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }
};

int main() {
    Stack s;

    // Initial stack elements (as shown in image)
    s.push(6);
    s.push(7);
    s.push(2);
    s.push(1);

    s.push(4);   // Push operation
    s.display();

    s.pop();     // Pop operation
    s.display();

    return 0;
}

