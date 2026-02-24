#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

// --- Node Structure ---
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {} 
};

// --- Improved Sorting & List Logic ---
void insert(Node*& head, Node*& tail, int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void bubbleSort(Node* head) {
    if (!head || !head->next) return;
    bool swapped;
    Node* lastPtr = nullptr; 
    do {
        swapped = false;
        Node* ptr = head;
        while (ptr->next != lastPtr) {
            if (ptr->data > ptr->next->data) {
                // Swapping data values
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = true;
            }
            ptr = ptr->next;
        }
        lastPtr = ptr; 
    } while (swapped);
}

void freeList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Helper to convert linked list to string format for the table
string listToString(Node* head) {
    if (!head) return "[]";
    stringstream ss;
    ss << "[";
    for (Node* t = head; t; t = t->next) {
        ss << t->data << (t->next ? " " : "");
    }
    ss << "]";
    return ss.str();
}

// --- Testbench Execution ---
void runTest(int id, string category, vector<int> inputData, vector<int> expectedData) {
    Node* head = nullptr;
    Node* tail = nullptr;
    
    // Create list
    for (int x : inputData) insert(head, tail, x);

    // Initial string representation
    stringstream ssIn;
    ssIn << "[";
    for(size_t i=0; i<inputData.size(); ++i) ssIn << inputData[i] << (i==inputData.size()-1 ? "" : " ");
    ssIn << "]";
    string inputStr = ssIn.str();

    // Sort
    bubbleSort(head);
    string actualStr = listToString(head);
    
    // Expected string representation
    stringstream ssExp;
    ssExp << "[";
    for(size_t i=0; i<expectedData.size(); ++i) ssExp << expectedData[i] << (i==expectedData.size()-1 ? "" : " ");
    ssExp << "]";
    string expectedStr = ssExp.str();

    bool passed = (actualStr == expectedStr);

    // PRINT TABLE ROW
    cout << left << setw(4) << id 
         << setw(12) << category 
         << setw(20) << inputStr 
         << setw(20) << expectedStr 
         << setw(20) << actualStr 
         << (passed ? "PASS" : "FAIL") << endl;

    freeList(head);
}

int main() {
    // Table Header
    cout << left << setw(4) << "ID" 
         << setw(12) << "Category" 
         << setw(20) << "Input" 
         << setw(20) << "Expected" 
         << setw(20) << "Actual" 
         << "Status" << endl;
    cout << string(85, '-') << endl;

    // 20 MANDATORY TEST CASES
    runTest(1, "Normal", {5, 2, 8, 1}, {1, 2, 5, 8});
    runTest(2, "Normal", {10, 5, 2}, {2, 5, 10});
    runTest(3, "Normal", {3, 1, 2}, {1, 2, 3});
    runTest(4, "Normal", {9, 7, 5, 3, 1}, {1, 3, 5, 7, 9});
    runTest(5, "Normal", {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5});
    
    runTest(6, "Edge", {1}, {1});
    runTest(7, "Edge", {}, {});
    runTest(8, "Edge", {2, 2, 2}, {2, 2, 2});
    runTest(9, "Edge", {1, 2}, {1, 2});
    runTest(10, "Edge", {2, 1}, {1, 2});
    
    runTest(11, "Negative", {-1, -5, 0}, {-5, -1, 0});
    runTest(12, "Negative", {-10, -30, -20}, {-30, -20, -10});
    runTest(13, "Duplicates", {3, 1, 3, 1}, {1, 1, 3, 3});
    runTest(14, "Duplicates", {0, 5, 0, 5}, {0, 0, 5, 5});
    runTest(15, "Extreme", {2147483647, 0, -2147483647}, {-2147483647, 0, 2147483647});
    
    runTest(16, "Special", {100, 50, 75}, {50, 75, 100});
    runTest(17, "Special", {0, -1, 1}, {-1, 0, 1});
    runTest(18, "Order", {10, 9, 8, 7}, {7, 8, 9, 10});
    runTest(19, "Stress", {1000, 200, 500}, {200, 500, 1000});
    runTest(20, "Stress", {4, 3, 2, 1, 0}, {0, 1, 2, 3, 4});

    return 0;
}
