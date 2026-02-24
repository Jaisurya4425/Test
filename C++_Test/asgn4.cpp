#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cctype>

using namespace std;

/**
 * IMPROVED LOGIC
 * Fixes the punctuation error where words after hyphens/dots weren't capitalized.
 */
string processTitleCase(string line) {
    bool newWord = true;
    for (int i = 0; i < line.length(); i++) {
        if (newWord && isalpha(line[i])) {
            line[i] = toupper(line[i]);
            newWord = false;
        } 
        // FIX: Any non-alpha char (comma, hyphen, number, etc.) triggers a new word
        else if (!isalpha(line[i])) {
            newWord = true;
        }
    }
    return line;
}

// Logic from your original code (for comparison in the table)
string originalLogic(string line) {
    bool newWord = true;
    for (int i = 0; i < line.length(); i++) {
        if (newWord && isalpha(line[i])) {
            line[i] = toupper(line[i]);
            newWord = false;
        } 
        else if (line[i] == ' ' || line[i] == '\t') {
            newWord = true;
        }
    }
    return line;
}

struct TestCase {
    int id;
    string category;
    string input;
    string expected;
};

int main() {
    vector<TestCase> tests = {
        {1, "Normal", "hello world", "Hello World"},
        {2, "Normal", "programming is awesome", "Programming Is Awesome"},
        {3, "Normal", "a b c", "A B C"},
        {4, "Normal", "SINGLE", "SINGLE"},
        {5, "Normal", "mixed CASE string", "Mixed CASE String"},
        {6, "Edge", "  leading space", "  Leading Space"},
        {7, "Edge", "trailing space  ", "Trailing Space  "},
        {8, "Edge", "multiple   spaces", "Multiple   Spaces"},
        {9, "Edge", "\ttabbed\tinput", "\tTabbed\tInput"},
        {10, "Edge", "", ""},
        {11, "Punctuation", "well-known", "Well-Known"},
        {12, "Punctuation", "it's a test", "It'S A Test"},
        {13, "Punctuation", "end.start", "End.Start"},
        {14, "Punctuation", "(bracket)test", "(Bracket)Test"},
        {15, "Punctuation", "word1,word2", "Word1,Word2"},
        {16, "Special", "123hello", "123Hello"},
        {17, "Special", "hello2world", "Hello2World"},
        {18, "Special", "!@#$%^", "!@#$%^"},
        {19, "Special", "  123  abc  ", "  123  Abc  "},
        {20, "Special", "new line", "New Line"}
    };

    // Table Header Printing
    cout << left << setw(4) << "ID" 
         << setw(12) << "Category" 
         << setw(25) << "Input" 
         << setw(25) << "Expected" 
         << setw(25) << "Actual" 
         << "Status" << endl;
    cout << string(100, '-') << endl;

    for (const auto& t : tests) {
        string actual = processTitleCase(t.input);
        string orig = originalLogic(t.input); // To show where yours would fail
        
        bool passed = (actual == t.expected);
        bool origPassed = (orig == t.expected);

        cout << left << setw(4) << t.id 
             << setw(12) << t.category 
             << setw(25) << t.input 
             << setw(25) << t.expected 
             << setw(25) << actual 
             << (passed ? "PASS" : "FAIL") << (origPassed ? "" : " (ORIGINAL FAILED)") << endl;
    }

    return 0;
}
