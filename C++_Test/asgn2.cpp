#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

// --- FIXED LOGIC FUNCTION ---
// Changes: Added null check and size validation.
int* sortArray(int* arr, int size) {
    if (arr == nullptr || size <= 0) return arr; 

    for (int i = 0; i < size - 1; i++) {
        int* min = arr + i;
        for (int j = i + 1; j < size; j++) {
            if (*(arr + j) < *min) {
                min = arr + j;
            }
        }
        if (min != (arr + i)) {
            int temp = *(arr + i);
            *(arr + i) = *min;
            *min = temp;
        }
    }
    return arr;
}

// --- TESTBENCH SYSTEM ---
void run_test(int id, string category, vector<int> input, vector<int> expected) {
    int size = input.size();
    int* testArr = (size > 0) ? new int[size] : nullptr;
    
    for(int i = 0; i < size; i++) testArr[i] = input[i];

    sortArray(testArr, size);

    bool passed = true;
    if (size > 0) {
        for(int i = 0; i < size; i++) {
            if (testArr[i] != expected[i]) passed = false;
        }
    }

    cout << left << setw(4) << id 
         << setw(15) << category 
         << setw(25) << (passed ? "PASS" : "FAIL") << endl;

    delete[] testArr;
}

int main() {
    cout << left << setw(4) << "ID" << setw(15) << "Category" << "Status" << endl;
    cout << "------------------------------------------" << endl;

    // 1-5 Normal Cases
    run_test(1, "Normal", {5, 3, 8, 1}, {1, 3, 5, 8});
    run_test(2, "Normal", {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    run_test(3, "Normal", {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5});
    run_test(4, "Normal", {-5, 2, 0, -10}, {-10, -5, 0, 2});
    run_test(5, "Normal", {100, 20, 50, 10}, {10, 20, 50, 100});

    // 6-10 Edge Cases
    run_test(6, "Single Element", {1}, {1});
    run_test(7, "All Same", {5, 5, 5, 5}, {5, 5, 5, 5});
    run_test(8, "Empty", {}, {});
    run_test(9, "Two Elements", {2, 1}, {1, 2});
    run_test(10, "Large Range", {1000, -1000, 0}, {-1000, 0, 1000});

    // 11-15 Mathematical/Specific Patterns
    run_test(11, "Duplicates", {3, 1, 2, 1, 3}, {1, 1, 2, 3, 3});
    run_test(12, "Already Sorted", {10, 20, 30}, {10, 20, 30});
    run_test(13, "Reverse Sorted", {30, 20, 10}, {10, 20, 30});
    run_test(14, "Zero Centric", {0, -1, 1, 0}, {-1, 0, 0, 1});
    run_test(15, "Max Ints", {2147483647, 0, -2147483647}, {-2147483647, 0, 2147483647});

    // 16-20 Randomized/Stress
    run_test(16, "Small Random", {4, 2, 7, 1}, {1, 2, 4, 7});
    run_test(17, "Large Negatives", {-100, -500, -200}, {-500, -200, -100});
    run_test(18, "Odd Size", {9, 1, 4}, {1, 4, 9});
    run_test(19, "Even Size", {8, 2, 5, 3}, {2, 3, 5, 8});
    run_test(20, "Alternating", {1, 10, 2, 9}, {1, 2, 9, 10});

    return 0;
}
