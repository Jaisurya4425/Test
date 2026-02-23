#include <iostream>

struct Node {
    int data;
    Node* next;
    // Constructor makes node creation cleaner
    Node(int val) : data(val), next(nullptr) {} 
};

// OPTIMIZATION 1: O(n) Insertion using a Tail Pointer
// The original was O(n^2) because it restarted from head every time.
void insert(Node*& head, Node*& tail, int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

// OPTIMIZATION 2: Optimized Bubble Sort
void bubbleSort(Node* head) {
    if (!head || !head->next) return;

    bool swapped;
    Node* ptr;
    Node* lastPtr = nullptr; // Optimization: Shrink the search range each pass

    do {
        swapped = false;
        ptr = head;

        while (ptr->next != lastPtr) {
            if (ptr->data > ptr->next->data) {
                // Keep data swapping logic as per original request
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = true;
            }
            ptr = ptr->next;
        }
        // After one full pass, the largest element is at the end.
        // lastPtr moves back so we don't re-check already sorted elements.
        lastPtr = ptr; 
    } while (swapped);
}

// OPTIMIZATION 3: Memory Management (Prevent Leaks)
void freeList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int n, value;

    if (!(std::cout << "Enter number of elements: " && std::cin >> n)) return 0;

    std::cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        std::cin >> value;
        insert(head, tail, value);
    }

    bubbleSort(head);

    std::cout << "Sorted List: ";
    for (Node* t = head; t; t = t->next) std::cout << t->data << " ";
    std::cout << std::endl;

    freeList(head); 
    return 0;
}
