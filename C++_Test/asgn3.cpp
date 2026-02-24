#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <iomanip>

using namespace std;

/**
 * FIXED LOGIC FUNCTION
 * Concatenates s1 and s2 into result with a space between them.
 * Returns "SUCCESS" or "BUFFER_OVERFLOW"
 */
string concatStrings(char* result, int resultSize, const char* s1, const char* s2) {
    if (!s1 || !s2 || !result) return "ERR: NULL";
    
    // CHANGE 1: Safety check to prevent memory corruption
    if (strlen(s1) + strlen(s2) + 2 > (size_t)resultSize) {
        return "ERR: OVERFLOW";
    }

    char *p = result;
    
    // Copy first string
    while ((*p = *s1) != '\0') {
        p++;
        s1++;
    }

    // Overwrite '\0' with space
    *p++ = ' ';

    // Copy second string
    while ((*p++ = *s2++) != '\0');

    return "SUCCESS";
}

void run_test(int id, string cat, string str1, string str2, string expected) {
    char result[150]; // Large buffer for testing
    memset(result, 0, sizeof(result));
    
    // We pass a smaller "logical" limit to test overflow logic
    string status = concatStrings(result, 100, str1.c_str(), str2.c_str());
    
    string actual = (status == "SUCCESS") ? string(result) : status;
    bool passed = (actual == expected);

    // CSV Output: ID, Category, Str1, Str2, Expected, Actual, Status
    cout << id << "," << cat << ",\"" << str1 << "\",\"" << str2 << "\",\"" 
         << expected << "\",\"" << actual << "\"," << (passed ? "PASS" : "FAIL") << endl;
}

int main() {
    cout << "Test ID,Category,Str1,Str2,Expected Output,Actual Output,Status" << endl;

    // 1-5 Normal Cases
    run_test(1, "Normal", "Hello", "World", "Hello World");
    run_test(2, "Normal", "Programming", "is awesome.", "Programming is awesome.");
    run_test(3, "Normal", "C++", "Pointers", "C++ Pointers");
    run_test(4, "Normal", "A", "B", "A B");
    run_test(5, "Normal", "Open", "AI", "Open AI");

    // 6-10 Edge Cases (Empty/Spaces)
    run_test(6, "Edge", "", "EmptyStart", " EmptyStart");
    run_test(7, "Edge", "EmptyEnd", "", "EmptyEnd ");
    run_test(8, "Edge", "", "", " ");
    run_test(9, "Edge", " ", " ", "   ");
    run_test(10, "Edge", "Tab\t", "Newline\n", "Tab\t Newline\n");

    // 11-15 Special Characters/Long
    run_test(11, "Special", "123", "456", "123 456");
    run_test(12, "Special", "!@#", "$%^", "!@# $%^");
    run_test(13, "Special", "StringWith'Quotes'", "End", "StringWith'Quotes' End");
    run_test(14, "Special", "Back\\slash", "Forward/slash", "Back\\slash Forward/slash");
    run_test(15, "Special", "Long_Variable_Name_Test", "Part2", "Long_Variable_Name_Test Part2");

    // 16-20 Logic & Error Handling
    run_test(16, "Logic", "Case", "Sensitive", "Case Sensitive");
    run_test(17, "Logic", "UPPER", "lower", "UPPER lower");
    run_test(18, "Overflow", string(60, 'a'), string(60, 'b'), "ERR: OVERFLOW");
    run_test(19, "Overflow", string(98, 'z'), "!", "ERR: OVERFLOW");
    run_test(20, "Logic", "Double  ", "  Space", "Double     Space");

    return 0;
}
