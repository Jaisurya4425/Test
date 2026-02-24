#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

// --- Node Structure ---
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// --- BST Logic ---
Node* insert(Node* root, int value) {
    if (root == nullptr) return new Node(value);
    if (value < root->data) root->left = insert(root->left, value);
    else root->right = insert(root->right, value);
    return root;
}

void getInorder(Node* root, stringstream& ss) {
    if (!root) return;
    ss << root->data << " ";
    getInorder(root->left, ss);
    getInorder(root->right, ss);
}

void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete(root);
}

// --- Testbench Helper ---
struct TestResult {
    string inorder;
    bool passed;
};

TestResult run_test(const vector<int>& inputs, const string& expectedInorder) {
    Node* root = nullptr;
    for (int val : inputs) root = insert(root, val);

    stringstream ss;
    getInorder(root, ss);
    string actual = ss.str();
    if (!actual.empty() && actual.back() == ' ') actual.pop_back();

    deleteTree(root);
    return {actual, actual == expectedInorder};
}

int main() {
    // CSV Header for Console
    cout << left << setw(4) << "ID" << setw(12) << "Category" << setw(25) << "Input Array" 
         << setw(20) << "Expected Inorder" << setw(20) << "Actual Inorder" << "Status" << endl;
    cout << string(95, '-') << endl;

    // 20 Mandatory Test Cases
    struct TestCase { int id; string cat; vector<int> in; string exp; };
    vector<TestCase> tests = {
        {1, "Normal", {9, 4, 15}, "4 9 15"},
        {2, "Normal", {10, 5, 15, 2, 7}, "2 5 7 10 15"},
        {3, "Normal", {1, 2, 3}, "1 2 3"},
        {4, "Normal", {3, 2, 1}, "1 2 3"},
        {5, "Normal", {50, 30, 70, 20, 40}, "20 30 40 50 70"},
        {6, "Edge", {5}, "5"},
        {7, "Edge", {}, ""},
        {8, "Duplicates", {10, 10}, "10 10"},
        {9, "Duplicates", {5, 3, 5}, "3 5 5"},
        {10, "Skewed-L", {5, 4, 3, 2}, "2 3 4 5"},
        {11, "Skewed-R", {1, 2, 3, 4}, "1 2 3 4"},
        {12, "Negatives", {-5, -10, 0}, "-10 -5 0"},
        {13, "Negatives", {-1, -2, -3}, "-3 -2 -1"},
        {14, "Balanced", {10, 5, 15}, "5 10 15"},
        {15, "Mixed", {100, 50, 150, 25, 75}, "25 50 75 100 150"},
        {16, "Special", {0, 0, 0}, "0 0 0"},
        {17, "Special", {8, 4, 12, 2, 6, 10, 14}, "2 4 6 8 10 12 14"},
        {18, "Order", {1, 5, 2, 4, 3}, "1 2 3 4 5"},
        {19, "Extreme", {2147483647, -2147483647}, "-2147483647 2147483647"},
        {20, "Stress", {10, 20, 15, 5, 7}, "5 7 10 15 20"}
    };

    for (const auto& t : tests) {
        stringstream ss;
        ss << "[";
        for(size_t i=0; i<t.in.size(); ++i) ss << t.in[i] << (i==t.in.size()-1?"":" ");
        ss << "]";
        
        TestResult res = run_test(t.in, t.exp);
        cout << left << setw(4) << t.id 
             << setw(12) << t.cat 
             << setw(25) << ss.str()
             << setw(20) << t.exp 
             << setw(20) << res.inorder 
             << (res.passed ? "PASS" : "FAIL") << endl;
    }

    return 0;
}
