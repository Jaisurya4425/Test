#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// --- The Logic Under Test ---
// Refactored into a function for systematic testing
string multiplyMatrices(int r1, int c1, int r2, int c2, const vector<vector<int>>& m1, const vector<vector<int>>& m2, vector<vector<int>>& result) {
    if (r1 <= 0 || c1 <= 0 || r2 <= 0 || c2 <= 0) return "Invalid Dimensions";
    if (c1 != r2) return "Dimension Mismatch";

    // Initialize result to 0
    result.assign(r1, vector<int>(c2, 0));

    // Optimized i-k-j multiplication
    for (int i = 0; i < r1; i++) {
        for (int k = 0; k < c1; k++) {
            int temp = m1[i][k];
            for (int j = 0; j < c2; j++) {
                result[i][j] += temp * m2[k][j];
            }
        }
    }
    return "Success";
}

// --- Testbench Utility ---
void run_test(int id, int r1, int c1, int r2, int c2, vector<vector<int>> m1, vector<vector<int>> m2, vector<vector<int>> expected) {
    vector<vector<int>> result;
    string status = multiplyMatrices(r1, c1, r2, c2, m1, m2, result);
    
    bool passed = false;
    if (status == "Success" && result == expected) passed = true;
    else if (status != "Success" && expected.empty()) passed = true; // Expected failure

    cout << "| " << setw(2) << id << " | " << r1 << "x" << c1 << " * " << r2 << "x" << c2 
         << " | " << (passed ? "PASS" : "FAIL") << " | " << status << " |" << endl;
}

int main() {
    cout << "Starting Matrix Multiplication Testbench (20 Cases)...\n";
    cout << "---------------------------------------------------------\n";
    cout << "| ID | Dimensions  | Status | Result Message       |\n";
    cout << "---------------------------------------------------------\n";

    // 1-5: Normal Cases (Standard Small Matrices)
    run_test(1, 2, 2, 2, 2, {{1,2},{3,4}}, {{5,6},{7,8}}, {{19,22},{43,50}});
    run_test(2, 2, 1, 1, 2, {{2},{3}}, {{4,5}}, {{8,10},{12,15}});
    run_test(3, 1, 2, 2, 1, {{1,2}}, {{3},{4}}, {{11}});
    run_test(4, 3, 3, 3, 3, {{1,0,0},{0,1,0},{0,0,1}}, {{1,2,3},{4,5,6},{7,8,9}}, {{1,2,3},{4,5,6},{7,8,9}});
    run_test(5, 2, 3, 3, 2, {{1,2,3},{4,5,6}}, {{7,8},{9,10},{11,12}}, {{58,64},{139,154}});

    // 6-10: Edge Cases (Identity, Zero, Single Element)
    run_test(6, 1, 1, 1, 1, {{5}}, {{10}}, {{50}});
    run_test(7, 2, 2, 2, 2, {{0,0},{0,0}}, {{1,2},{3,4}}, {{0,0},{0,0}});
    run_test(8, 2, 2, 2, 2, {{1,2},{3,4}}, {{0,0},{0,0}}, {{0,0},{0,0}});
    run_test(9, 3, 3, 3, 3, {{1,2,3},{4,5,6},{7,8,9}}, {{1,0,0},{0,1,0},{0,0,1}}, {{1,2,3},{4,5,6},{7,8,9}});
    run_test(10, 2, 2, 2, 2, {{1,1},{1,1}}, {{1,1},{1,1}}, {{2,2},{2,2}});

    // 11-15: Invalid Input Cases (Mismatched Dimensions)
    run_test(11, 2, 3, 2, 2, {{1,2,3},{4,5,6}}, {{1,2},{3,4}}, {}); // Empty expected = expect fail
    run_test(12, 1, 1, 2, 1, {{1}}, {{1},{2}}, {});
    run_test(13, 0, 0, 0, 0, {}, {}, {});
    run_test(14, -1, 5, 5, 2, {}, {}, {});
    run_test(15, 2, 2, 3, 3, {{1,1},{1,1}}, {{1,1,1},{1,1,1},{1,1,1}}, {});

    // 16-20: Mathematical Properties (Negative numbers, Large values)
    run_test(16, 2, 2, 2, 2, {{-1,-2},{-3,-4}}, {{1,2},{3,4}}, {{-7,-10},{-15,-22}});
    run_test(17, 2, 2, 2, 2, {{1,-1},{-1,1}}, {{1,1},{1,1}}, {{0,0},{0,0}});
    run_test(18, 1, 4, 4, 1, {{1,2,3,4}}, {{1},{1},{1},{1}}, {{10}});
    run_test(19, 2, 2, 2, 2, {{10,20},{30,40}}, {{5,5},{5,5}}, {{150,150},{350,350}});
    run_test(20, 2, 2, 2, 2, {{1,2},{3,4}}, {{1,0},{0,1}}, {{1,2},{3,4}});

    cout << "---------------------------------------------------------\n";
    return 0;
}
