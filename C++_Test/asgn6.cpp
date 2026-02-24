#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

// --- REFACTORED LOGIC ---
// Encapsulating the logic to handle various stack operations safely
struct StackResult {
    string finalStack;
    string poppedElement;
    string topElement;
    string status;
};

StackResult processStack(vector<int> initialData, int pushVal, bool shouldPop) {
    stack<int> s;
    StackResult res;
    res.status = "SUCCESS";

    // Push initial elements
    for (int x : initialData) s.push(x);

    // Operation 1: Push new element
    s.push(pushVal);

    // Operation 2: Pop top element
    if (shouldPop) {
        if (!s.empty()) {
            res.poppedElement = to_string(s.top());
            s.pop();
        } else {
            res.status = "ERR_UNDERFLOW";
            res.poppedElement = "N/A";
        }
    } else {
        res.poppedElement = "NONE";
    }

    // Operation 3: Peek top
    if (!s.empty()) {
        res.topElement = to_string(s.top());
    } else {
        res.topElement = "EMPTY";
    }

    // Convert final stack to string for reporting
    stringstream ss;
    ss << "[";
    stack<int> temp = s;
    while (!temp.empty()) {
        ss << temp.top() << (temp.size() > 1 ? " " : "");
        temp.pop();
    }
    ss << "]";
    res.finalStack = ss.str();

    return res;
}

// --- TESTBENCH SYSTEM ---
int main() {
    struct TestData {
        int id;
        string cat;
        vector<int> init;
        int pushV;
        bool doPop;
        string expectedTop;
    };

    vector<TestData> tests = {
        {1, "Normal", {6, 7, 2, 1}, 4, true, "1"},
        {2, "Normal", {10, 20}, 30, true, "20"},
        {3, "Normal", {1}, 2, true, "1"},
        {4, "Normal", {5, 5, 5}, 10, true, "5"},
        {5, "Normal", {1, 2, 3}, 0, true, "3"},
        {6, "Edge", {}, 99, true, "EMPTY"},
        {7, "Edge", {}, 5, false, "5"},
        {8, "Edge", {100}, 200, true, "100"},
        {9, "Edge", {1, 2, 3, 4, 5}, 6, false, "6"},
        {10, "Edge", {0}, 0, true, "0"},
        {11, "Multi", {10, 10}, 10, true, "10"},
        {12, "Multi", {1, 2, 1, 2}, 3, true, "2"},
        {13, "Negatives", {-1, -2}, -3, true, "-2"},
        {14, "Negatives", {-10}, 0, true, "-10"},
        {15, "Large", {2147483647}, 1, true, "2147483647"},
        {16, "Special", {0, 0}, 0, false, "0"},
        {17, "Special", {1, 0, 1}, 0, true, "1"},
        {18, "Order", {5, 4, 3, 2}, 1, true, "2"},
        {19, "Order", {10, 20, 30}, 40, false, "40"},
        {20, "Stress", {1, 1, 1, 1, 1}, 2, true, "1"}
    };

    // Print Table Header
    cout << left << setw(4) << "ID" << setw(10) << "Category" << setw(18) << "Final Stack" 
         << setw(12) << "Popped" << setw(10) << "Top" << "Status" << endl;
    cout << string(65, '-') << endl;

    for (const auto& t : tests) {
        StackResult res = processStack(t.init, t.pushV, t.doPop);
        bool passed = (res.topElement == t.expectedTop);

        cout << left << setw(4) << t.id 
             << setw(10) << t.cat 
             << setw(18) << res.finalStack 
             << setw(12) << res.poppedElement 
             << setw(10) << res.topElement 
             << (passed ? "PASS" : "FAIL") << endl;
    }

    return 0;
}
