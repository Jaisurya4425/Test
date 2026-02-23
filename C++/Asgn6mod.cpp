
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;

    // Initial stack elements
    s.push(6);
    s.push(7);
    s.push(2);
    s.push(1);

    cout << "\nStack after insertion of 4:\n";
    s.push(4);

    // Display stack (using a copy)
    stack<int> temp = s;
    cout << "Stack elements :" << endl;
    while (!temp.empty()) {
        cout << temp.top() << endl;
        temp.pop();
    }

    cout << "\nAfter deletion of top element:\n";
    if (!s.empty()) {
        cout << s.top() << " popped from stack" << endl;
        s.pop();
    }

    // Display again
    temp = s;
    cout << "Stack elements :" << endl;
    while (!temp.empty()) {
        cout << temp.top() << endl;
        temp.pop();
    }

    // Peek top element
    if (!s.empty())
        cout << "\nTop element is: " << s.top() << endl;

    return 0;
}
