#include <iostream>
using namespace std;

// Structure for linked list node
struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node at end
void insertEnd(Node*& head, int value) {
    Node* newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Function to bubble sort the linked list
void bubbleSort(Node* head) {
    if (head == NULL) return;

    bool swapped;
    Node* ptr;
    Node* last = NULL;

    do {
        swapped = false;
        ptr = head;

        while (ptr->next != last) {
            if (ptr->data > ptr->next->data) {
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = true;
            }
            ptr = ptr->next;
        }
        last = ptr;
    } while (swapped);
}

// Function to display list
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        insertEnd(head, value);
    }

    cout << "Before Sorting:\n";
    display(head);

    bubbleSort(head);

    cout << "After Bubble Sorting:\n";
    display(head);

    return 0;
}

